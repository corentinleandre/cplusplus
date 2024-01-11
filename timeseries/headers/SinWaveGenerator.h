//
// Created by coren on 11/01/2024.
//

#ifndef TIMESERIES_SINWAVEGENERATOR_H
#define TIMESERIES_SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"

class SinWaveGenerator: public TimeSeriesGenerator{
private:
    double amplitude;
    double frequency;
    double initialPhase;
public:
    SinWaveGenerator();
    SinWaveGenerator(double amp, double freq, double phase);
    vector<double> generateTimeSeries(int) override;
};

#endif //TIMESERIES_SINWAVEGENERATOR_H
