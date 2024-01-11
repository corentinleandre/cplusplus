//
// Created by coren on 15/12/2023.
//

#ifndef POKEMON_TRAINERCARD_H
#define POKEMON_TRAINERCARD_H

#include "Card.h"
#include <string>
using namespace std;

class TrainerCard : public Card{
public:
    TrainerCard(const string&, const string&);
    void displayInfo() override;
    string getEffect() const;
private:
    string trainerEffect;
};

#endif //POKEMON_TRAINERCARD_H
