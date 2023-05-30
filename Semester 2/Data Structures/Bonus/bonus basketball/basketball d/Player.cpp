# include <iostream>
# include "Player.h"

Player:: Player(std::string name, std::string surname) {
    this->name = name;
    this->surname = surname;
}

std::string Player:: getName() {return name;}

std::string Player:: getSurname() {return surname;}

std::string Player:: getPlayerDescription() {
    return name + "-" + surname;
}
