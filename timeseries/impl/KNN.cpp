//
// Created by coren on 11/01/2024.
//

#include "../headers/TimeSeriesDataset.h"

#include "../headers/KNN.h"
#include <map>


KNN::KNN(int ks, const string & sim)
    :k(ks),similarity_measure(sim) {
}

double KNN::evaluate(TimeSeriesDataset & trainData, TimeSeriesDataset & testData, vector<int> truth) {
    double accuracy = 0;
    for(int i = 0; i < truth.size(); i++){
        if(predict(trainData, testData.getData()[i]) == truth[i]){
            accuracy += 1.0/double(truth.size());
        }
    }
    return accuracy;
}

int KNN::predict(TimeSeriesDataset & trainData, vector<double>& test) {
    std::map<double, int> map;
    std::map<int, unsigned int> classCount;
    vector<int> ret;
    vector<double> similarities;
    double similarity;
    for(unsigned int i = 0; i < trainData.getData().size(); i++){
        vector<double> data = trainData.getData()[i];
        if(similarity_measure == "dtw"){
            similarity = TimeSeriesDataset::dtw_distance(data, test);
        }else if(similarity_measure == "euclidian_distance"){
            similarity = TimeSeriesDataset::euclidian_distance(data, test);
        }
        map.emplace(similarity, trainData.getLabels()[i]);
        similarities.insert(std::lower_bound(similarities.begin(), similarities.end(), similarity), similarity);
    }
    for (int label : trainData.getLabels()){
        classCount.emplace(label, 0);
    }
    for(unsigned int j = 0; j < k; j++ ){
        classCount.at(map.at(similarities[j]))++;
    }
    unsigned int max = 0;
    int prediction = -1;
    for( const auto& kv : classCount){
        if(kv.second > max){
            max = kv.second;
            prediction = kv.first;
        }
    }
    return prediction;
}

