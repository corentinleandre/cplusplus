//
// Created by coren on 15/12/2023.
//

#include "Card.h"
#include "iostream"

Card::Card(const string& name):
    cardName(name){
}

string Card::getName() const {
    return cardName;
}