//
// Created by coren on 11/01/2024.
//

#ifndef TIMESERIES_TIMESERIESDATASET_H
#define TIMESERIES_TIMESERIESDATASET_H

#include <vector>

class TimeSeriesDataset {
private:
    bool zNormalize;
    bool isTrain;
    std::vector<std::vector<double>> data;
    std::vector<int> labels;
    int maxLength;
    int numberOfSamples;

    static std::vector<double> normalize(const std::vector<double>&);

public:
    // Default Constructor
    TimeSeriesDataset();

    // Parameterized Constructor
    TimeSeriesDataset(bool zNorm, bool isTr);

    // Getter methods
    bool getZNormalize() const;
    bool getIsTrain() const;
    std::vector<std::vector<double>> getData() const;
    std::vector<int> getLabels() const;
    int getMaxLength() const;
    int getNumberOfSamples() const;

    void addTimeSeries(const std::vector<double>&, int);
    void addTimeSeries(const std::vector<double>&);
    static double euclidian_distance(const std::vector<double>&, const std::vector<double>&);
    static double dtw_distance(const std::vector<double>&, const std::vector<double>&);
};

#endif //TIMESERIES_TIMESERIESDATASET_H
