//
// Created by coren on 15/12/2023.
//

#include <iostream>
#include "TrainerCard.h"

TrainerCard::TrainerCard(const std::string & _name, const std::string & _effect):
    Card(_name), trainerEffect(_effect){
}

void TrainerCard::displayInfo() {
    std::cout << std::endl << "Trainer Card - Name: " << getName() << ", Effect: " << trainerEffect;
}

string TrainerCard::getEffect() const {
    return trainerEffect;
}

