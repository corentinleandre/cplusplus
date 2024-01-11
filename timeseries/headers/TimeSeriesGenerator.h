//
// Created by coren on 08/01/2024.
//

#ifndef TIMESERIES_TIMESERIESGENERATOR_H
#define TIMESERIES_TIMESERIESGENERATOR_H

#include <vector>
using namespace std;

class TimeSeriesGenerator{
public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int);
    virtual vector<double> generateTimeSeries(int) = 0;
    static void printTimeSeries(const vector<double>&);
private:
    static int random_seed();
    int seed;
};

#endif //TIMESERIES_TIMESERIESGENERATOR_H
