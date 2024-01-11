//
// Created by coren on 15/12/2023.
//

#ifndef POKEMON_ENERGYCARD_H
#define POKEMON_ENERGYCARD_H

#include "Card.h"
#include <string>
using namespace std;

class EnergyCard : public Card{
public:
    EnergyCard(const string&);
    void displayInfo() override;
    string getEnergyType() const;
private:
    string energyType;
};

#endif //POKEMON_ENERGYCARD_H
