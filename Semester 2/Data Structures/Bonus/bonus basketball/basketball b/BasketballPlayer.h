# pragma once

# include <iostream>
# include "Player.h"

class BasketballPlayer : public Player {
    protected:
    std::string position;

    public:
    // constructor
    BasketballPlayer(std::string name, std::string surname, std::string position);
    // getter
    std::string getPosition();
    std::string getPlayerDescription();
};