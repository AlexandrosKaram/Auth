# include <iostream>
# include "BasketballPlayer.h"

BasketballPlayer:: BasketballPlayer(std::string name, std::string surname, std::string position) :
Player(name, surname) {
    this->position = position;
}

std::string BasketballPlayer:: getPosition () {return position;}
