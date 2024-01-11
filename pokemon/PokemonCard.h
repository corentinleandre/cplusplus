//
// Created by coren on 15/12/2023.
//

#ifndef POKEMON_POKEMONCARD_H
#define POKEMON_POKEMONCARD_H

#include <string>
#include <vector>
#include <tuple>
#include "Card.h"

using namespace std;

class PokemonCard : public Card {
public:
    PokemonCard(const string& name, const string& _pokemonType, const string& _familyName, int _evolutionLevel,
                int _maxHP,
                int attack1Energy, const string& attack1Name, int attack1Damage,
                int attack2Energy, const string& attack2Name, int attack2Damage);
    static vector<tuple<int, string, int>>* generateAttacksVector(int attack1Energy, const string& attack1Name, int attack1Damage,
                                                           int attack2Energy, const string& attack2Name, int attack2Damage);
    string getPokemonType() const;
    string getFamilyName() const;
    int getEvolutionLevel() const;
    int getHP() const;
    void setHP(int);
    int getMaxHP() const;
    int getAttachedEnergy() const;
    void setAttachedEnergy(const int);
    vector<tuple<int, string, int>>* getAttacks() const;
    void displayInfo() override;
    void attachEnergy();
    void detachEnergy(int);
private:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    int attachedEnergy;
    vector<tuple<int, string, int>>* attacks;
};

#endif //POKEMON_POKEMONCARD_H
