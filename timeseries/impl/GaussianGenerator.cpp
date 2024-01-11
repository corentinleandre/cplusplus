//
// Created by coren on 10/01/2024.
//

#include "../headers/GaussianGenerator.h"
#include <random>

vector<double> GaussianGenerator::generateTimeSeries(int outputNumber) {
    vector<double> ret;

    //random seed
    std::random_device rd;
    //engine with seed
    std::mt19937 rng(rd());

    //distribution
    std::uniform_real_distribution<double> distrib(0.0, 1.0);

    for(unsigned int i = 0; i < outputNumber; i++){
        double u1 = 1.0 - distrib(rng);
        double u2 = 1.0 - distrib(rng);

        ret.push_back(sqrt(-2 * log(u1)) * cos(2 * M_PI * u2));
    }

    return ret;
}
