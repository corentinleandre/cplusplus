//
// Created by coren on 15/12/2023.
//

#include "EnergyCard.h"
#include <iostream>
using namespace std;

EnergyCard::EnergyCard(const std::string& name):
        Card("Energy"), energyType(name){
}

void EnergyCard::displayInfo() {
    cout << endl;
}

string EnergyCard::getEnergyType() const {
    return energyType;
}
