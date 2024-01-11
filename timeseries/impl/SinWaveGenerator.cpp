//
// Created by coren on 11/01/2024.
//
#include "../headers/SinWaveGenerator.h"
#include <math.h>

// Default Constructor
SinWaveGenerator::SinWaveGenerator() : amplitude(1.0), frequency(1.0), initialPhase(0.0) {
    // Default values for amplitude, frequency, and initialPhase
}

// Parameterized Constructor
SinWaveGenerator::SinWaveGenerator(double amp, double freq, double phase)
        : amplitude(amp), frequency(freq), initialPhase(phase) {
    // Initialize the members with the provided values
}

// Implementation of generateTimeSeries method
vector<double> SinWaveGenerator::generateTimeSeries(int numPoints) {
    vector<double> timeSeries;

    double step = (M_PI / numPoints);
    double x;
    for(int i = 0; i < numPoints; i++){
        x = i * step;
        // formula for sine wave
        timeSeries.push_back( amplitude * sin(x * frequency + initialPhase));
    }
    return timeSeries;
}