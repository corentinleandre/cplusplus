//
// Created by coren on 15/12/2023.
//

#include <iostream>
#include "PokemonCard.h"

PokemonCard::PokemonCard(const string& name, const string& _pokemonType, const string& _familyName, const int _evolutionLevel,
                         int _maxHP,
                         int attack1Energy, const string& attack1Name, int attack1Damage,
                         int attack2Energy, const string& attack2Name, int attack2Damage)
        : Card(name), pokemonType(_pokemonType), familyName(_familyName), evolutionLevel(_evolutionLevel),
          maxHP(_maxHP), hp(_maxHP), attachedEnergy(0), attacks(generateAttacksVector(attack1Energy,attack1Name,attack1Damage,attack2Energy,attack2Name,attack2Damage)) {
}

vector<tuple<int, string, int>>* PokemonCard::generateAttacksVector(int attack1Energy, const string& attack1Name, int attack1Damage,
                                                                    int attack2Energy, const string& attack2Name, int attack2Damage) {
    auto* generated_attacks = new vector<tuple<int, string, int>>();

    // Add attack 1 details to the attacks vector
    generated_attacks->emplace_back(attack1Energy, attack1Name, attack1Damage);

    // Add attack 2 details to the attacks vector
    generated_attacks->emplace_back(attack2Energy, attack2Name, attack2Damage);

    return generated_attacks;
}

void PokemonCard::displayInfo() {
    std::cout << std::endl << "Pokemon Card - Name:" << getName() << ", Type:" << pokemonType <<
    ", Evolution Level: " << evolutionLevel << " of the family " << familyName  << std::endl;
    std::cout <<"HP: " << hp << ", Attached Energy : " << attachedEnergy << std::endl;
    std::cout << "Attacks" << std::endl;
    for (unsigned int i = 0; i < attacks->size(); i++) {
        auto attack = (*attacks)[i];
        std::cout << "Attack #" << i << ":" << std::endl;
        std::cout << "Attack cost: " << get<0>(attack) << std::endl;
        std::cout << "Attack description: " << get<1>(attack) << std::endl;
        std::cout << "Attack damage: " << get<2>(attack) << std::endl;
    }
}

void PokemonCard::attachEnergy() {
    attachedEnergy += 1;
}

void PokemonCard::detachEnergy(int detaching) {
    if(attachedEnergy < detaching){
        throw exception();
    }
    attachedEnergy -= detaching;
}

void PokemonCard::setHP(int newHP) {
    hp = newHP;
}

string PokemonCard::getPokemonType() const {
    return pokemonType;
}

int PokemonCard::getAttachedEnergy() const {
    return attachedEnergy;
}

vector<tuple<int, string, int>> *PokemonCard::getAttacks() const {
    return attacks;
}

int PokemonCard::getHP() const {
    return hp;
}

string PokemonCard::getFamilyName() const {
    return familyName;
}

int PokemonCard::getMaxHP() const {
    return maxHP;
}

void PokemonCard::setAttachedEnergy(const int newInt) {
    attachedEnergy = newInt;
}

int PokemonCard::getEvolutionLevel() const {
    return evolutionLevel;
}



