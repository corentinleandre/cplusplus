cmake_minimum_required(VERSION 3.26)
project(pokemon)

set(CMAKE_CXX_STANDARD 17)

add_executable(pokemon main.cpp
        Card.h
        Card.cpp
        PokemonCard.h
        EnergyCard.h
        TrainerCard.h
        PokemonCard.cpp
        TrainerCard.cpp
        EnergyCard.cpp
        Player.h
        Player.cpp)
