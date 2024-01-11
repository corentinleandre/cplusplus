//
// Created by coren on 22/12/2023.
//

#ifndef POKEMON_PLAYER_H
#define POKEMON_PLAYER_H

#include <vector>
#include <string>
#include "Card.h"
#include "PokemonCard.h"

using namespace std;


class Player{
public:
    Player(const string& name);
    void addCardToBench(Card*);
    void activatePokemonCard(int);
    void attachEnergyCard(int, int);
    void displayBench();
    void displayAction();
    void attack(int, int, Player&, int);
    void useTrainer(int);
private:
    string name;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;
};

#endif //POKEMON_PLAYER_H
