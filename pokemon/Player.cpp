//
// Created by coren on 22/12/2023.
//
#include "Player.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include <iostream>
using namespace std;

Player::Player(const std::string& _name):
    name(_name), benchCards(vector<Card*>()), actionCards(vector<PokemonCard*>()){
}

void Player::addCardToBench(Card* inCard) {
    benchCards.push_back(inCard);
}

void Player::activatePokemonCard(int index) {
    if(index >= benchCards.size()) {
        throw exception();
    }
    //On crée par recopie ! pour eviter les fuites mémoire type un pointeur dans 2 vectors
    auto activePokemon = new PokemonCard(*dynamic_cast<PokemonCard*>(benchCards[index]));
    if(activePokemon == nullptr){
        throw exception();
    }
    actionCards.push_back(activePokemon);

    cout << name << " is activating a Pokemon card : " << activePokemon->getName() << endl;
    delete benchCards[index];
    benchCards.erase(benchCards.begin()+index);
}

void Player::attachEnergyCard(int benchCardIndex, int actionPokemonIndex) {
    if (benchCardIndex >= benchCards.size()){
        throw exception();
    }
    if (actionPokemonIndex >= actionCards.size()){
        throw exception();
    }
    auto energyCard = dynamic_cast<EnergyCard*>(benchCards[benchCardIndex]);
    if(energyCard == nullptr){
        throw exception();
    }
    PokemonCard* pokemonCard = actionCards[actionPokemonIndex];
    if(pokemonCard->getPokemonType() == energyCard->getEnergyType()){
        cout << name << " is attaching Energy Card of type " << energyCard->getEnergyType() << " to the Pokemon : " << pokemonCard->getName() << endl;
        pokemonCard->attachEnergy();
        delete benchCards[benchCardIndex];
        benchCards.erase(benchCards.begin()+benchCardIndex);
    }
}

void Player::displayBench() {
    cout << "Bench cards for player " << name << ":";
    for(Card* cp : benchCards){
        cp->displayInfo();
        cout << endl;
    }
}

void Player::displayAction() {
    cout << "Action cards for player " << name << ":";
    for(PokemonCard* pcp : actionCards){
        pcp->displayInfo();
        cout << endl;
    }
}

void Player::attack(int pokemonIndex, int attackIndex, Player & enemy, int enemyPokemonIndex) {
    if(pokemonIndex >= actionCards.size()){
        throw exception();
    }
    if(attackIndex >= 2){
        throw exception();
    }
    if(enemyPokemonIndex >= enemy.actionCards.size()){
        throw exception();
    }
    //auto but we know the type (tuple<int, string,int>)
    auto attack = actionCards[pokemonIndex]->getAttacks()->operator[](attackIndex);
    if(actionCards[pokemonIndex]->getAttachedEnergy() >= get<0>(attack)){
        actionCards[pokemonIndex]->detachEnergy(get<0>(attack));
        //attack success
        cout << name << " is attacking " << enemy.name << "'s Pokemon " << enemy.actionCards[enemyPokemonIndex]->getName()
        << " with his Pokemon " << actionCards[pokemonIndex]->getName()
        << "'s attack " << get<1>(attack) << endl;
        //Doing the math
        enemy.actionCards[enemyPokemonIndex]->setHP(enemy.actionCards[enemyPokemonIndex]->getHP() - get<2>(attack));
        cout << "Subtracting " << get<2>(attack) << " from " << enemy.name << "'s Pokemon's HP !" << endl;
        cout << "Pokemon " << enemy.actionCards[enemyPokemonIndex]->getName();
        //alive check
        if(enemy.actionCards[enemyPokemonIndex]->getHP() > 0){
            cout << " is still alive";
        }else{
            cout << " fainted !";
        }
        cout << endl;
    }
}

void Player::useTrainer(int index) {
    if(index >= benchCards.size()) {
        throw exception();
    }

    //il va nulle part, pas besoin de recopie
    auto trainer = dynamic_cast<TrainerCard*>(benchCards[index]);
    if(trainer == nullptr){
        throw exception();
    }
    if(trainer->getEffect() == "heal all your action pokemon"){
        for(PokemonCard* pcp : actionCards){
            pcp->setHP(pcp->getMaxHP());
        }
    }

    cout << name << " is activating a Trainer card to \"" << trainer->getEffect() << "\"" << endl;
    delete benchCards[index];
    benchCards.erase(benchCards.begin()+index);
}

