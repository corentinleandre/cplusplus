//
// Created by coren on 15/12/2023.
//

#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include <string>

using namespace std;

class Card{
public:
    Card(const string&);
    virtual void displayInfo() = 0;
    string getName() const;
private:
    string cardName;
};

#endif //POKEMON_CARD_H
