#include "Professor.h"

Professor:: Professor(std::string surname) : Employee(surname) {}

int Professor:: getPublishes() {return publishes;}

void Professor:: setPublishes(int publishses) {
    this->publishes = publishes;
}