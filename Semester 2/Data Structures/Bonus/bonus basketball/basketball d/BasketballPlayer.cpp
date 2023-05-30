# include <iostream>
# include "BasketballPlayer.h"

BasketballPlayer:: BasketballPlayer(std::string name, std::string surname, std::string position) :
Player(name, surname) {
    this->position = position;
}

std::string BasketballPlayer:: getPosition () {return position;}

std::string BasketballPlayer:: getPlayerDescription() {
    if (position.length() >= 3) {
        return name + "-" + surname + "-" + position;
    } else {
        return name + "-" + surname + "-" + "unknown";
    }
}