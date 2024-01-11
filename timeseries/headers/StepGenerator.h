//
// Created by coren on 10/01/2024.
//

#ifndef TIMESERIES_STEPGENERATOR_H
#define TIMESERIES_STEPGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <random>

class StepGenerator: public TimeSeriesGenerator{
public:
    vector<double> generateTimeSeries(int) override;
};

vector<double> StepGenerator::generateTimeSeries(int outputNumber) {
    vector<double> ret;

    //random int generator
    std::random_device rd;
    //engine
    std::mt19937 rng(rd());

    //distribution
    std::uniform_int_distribution distrib(0,100);
    double last_value = 0;
    ret.push_back(last_value);

    for(unsigned int i = 0; i < outputNumber-1; i++){
        if(distrib(rng) < 50){
            last_value = distrib(rng);
            ret.push_back(last_value);
        }else{
            ret.push_back(last_value);
        }
    }

    return ret;
}

#endif //TIMESERIES_STEPGENERATOR_H
