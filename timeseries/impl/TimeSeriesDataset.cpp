//
// Created by coren on 11/01/2024.
//

#include "../headers/TimeSeriesDataset.h"
#include <execution>
#include <numeric>
#include <cmath>

TimeSeriesDataset::TimeSeriesDataset():
    zNormalize(false), isTrain(false), maxLength(10), data(), labels(), numberOfSamples(0){

}

TimeSeriesDataset::TimeSeriesDataset(bool zNorm, bool isTr)
    :zNormalize(zNorm), isTrain(isTr), maxLength(10), data(), labels(), numberOfSamples(0){
}

// Getter methods
bool TimeSeriesDataset::getZNormalize() const { return zNormalize; }
bool TimeSeriesDataset::getIsTrain() const { return isTrain; }
std::vector<std::vector<double>> TimeSeriesDataset::getData() const { return data; }
std::vector<int> TimeSeriesDataset::getLabels() const { return labels; }
int TimeSeriesDataset::getMaxLength() const { return maxLength; }
int TimeSeriesDataset::getNumberOfSamples() const { return numberOfSamples; }

void TimeSeriesDataset::addTimeSeries(const std::vector<double> & timeSerie, int label) {
    if(isTrain){
        labels.emplace_back(label);
    }
    if(zNormalize){
        data.emplace_back(normalize(timeSerie));
    }else{
        data.emplace_back(timeSerie);
    }
}

void TimeSeriesDataset::addTimeSeries(const std::vector<double> & timeSerie) {
    if(isTrain){
        throw std::exception();
    }else{
        data.emplace_back(timeSerie);
    }
}

std::vector<double> TimeSeriesDataset::normalize(const std::vector<double>& input) {
    //to do it in parallel
    double mean = std::reduce(std::execution::par, input.begin(), input.end()) / input.size();

    std::vector<double> vars;
    std::for_each(input.begin(), input.end(), [&mean, &vars](double element) {vars.emplace_back(pow((element-mean), 2));});
    double ect = sqrt(std::reduce(std::execution::par, vars.begin(), vars.end()) / input.size());

    std::vector<double> ret;
    //set the ret size with input size
    ret.reserve(input.size());
    //fill it
    for(double i : input){
        ret.emplace_back(i - mean / ect);
    }
    return ret;
}

double TimeSeriesDataset::euclidian_distance(const std::vector<double>& a, const std::vector<double>& b) {
    // Check if the two vectors have the same size
    if (a.size() != b.size()) {
        // Handle error (throw an exception, return a special value, etc.)
        // For simplicity, let's throw an exception here.
        throw std::invalid_argument("Vectors must have the same size for Euclidean distance calculation.");
    }

    // Calculate the Euclidean distance between vectors a and b
    double distance = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        distance += std::pow(a[i] - b[i], 2);
    }

    return std::sqrt(distance);
}

double TimeSeriesDataset::dtw_distance(const std::vector<double>& a, const std::vector<double>& b) {
    // Create a matrix to store the accumulated distances
    std::vector<std::vector<double>> dtwMatrix(a.size() + 1, std::vector<double>(b.size() + 1, 0.0));

    // Initialize the first row and column of the matrix
    for (size_t i = 1; i <= a.size(); ++i) {
        dtwMatrix[i][0] = std::numeric_limits<double>::infinity();
    }
    for (size_t j = 1; j <= b.size(); ++j) {
        dtwMatrix[0][j] = std::numeric_limits<double>::infinity();
    }

    // Fill the matrix with accumulated distances
    for (size_t i = 1; i <= a.size(); ++i) {
        for (size_t j = 1; j <= b.size(); ++j) {
            double cost = std::abs(a[i - 1] - b[j - 1]);
            dtwMatrix[i][j] = cost + std::min({ dtwMatrix[i - 1][j], dtwMatrix[i][j - 1], dtwMatrix[i - 1][j - 1] });
        }
    }

    // Return the DTW distance (bottom-right element of the matrix)
    return dtwMatrix[a.size()][b.size()];
}
