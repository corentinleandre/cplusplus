//
// Created by coren on 11/01/2024.
//

#ifndef TIMESERIES_KNN_H
#define TIMESERIES_KNN_H

#include <string>
#include "TimeSeriesDataset.h"

using namespace std;

class KNN{
private:
    unsigned int k;
    string similarity_measure;
    int predict(TimeSeriesDataset&, vector<double>&);
public:
    KNN(int, const string&);
    double evaluate(TimeSeriesDataset&, TimeSeriesDataset&, vector<int>);
};

#endif //TIMESERIES_KNN_H
