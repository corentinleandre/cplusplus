//
// Created by coren on 10/01/2024.
//

#ifndef TIMESERIES_GAUSSIANGENERATOR_H
#define TIMESERIES_GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"

class GaussianGenerator : public TimeSeriesGenerator{
public:
    vector<double> generateTimeSeries(int) override;

};

#endif //TIMESERIES_GAUSSIANGENERATOR_H
