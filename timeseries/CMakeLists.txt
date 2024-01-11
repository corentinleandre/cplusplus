cmake_minimum_required(VERSION 3.26)
project(timeseries)

set(CMAKE_CXX_STANDARD 17)

add_executable(timeseries main.cpp
        headers/TimeSeriesGenerator.h
        impl/TimeSeriesGenerator.cpp
        headers/GaussianGenerator.h
        impl/GaussianGenerator.cpp
        headers/StepGenerator.h
        impl/StepGenerator.cpp
        headers/SinWaveGenerator.h
        impl/SinWaveGenerator.cpp
        headers/TimeSeriesDataset.h
        impl/TimeSeriesDataset.cpp
        headers/KNN.h
        impl/KNN.cpp)
