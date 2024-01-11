//
// Created by coren on 08/01/2024.
//
#include "../headers/TimeSeriesGenerator.h"
#include <iostream>
#include <random>

TimeSeriesGenerator::TimeSeriesGenerator():
    seed(random_seed()){
}

TimeSeriesGenerator::TimeSeriesGenerator(int _seed):
    seed(_seed){
}

void TimeSeriesGenerator::printTimeSeries(const vector<double>& timeSeries) {
    for(double d : timeSeries){
        std::cout << d << ",";
    }
}

int TimeSeriesGenerator::random_seed() {
    //genrator with uniform repartition of ints
    std::random_device rd;

    return int(rd());
}

