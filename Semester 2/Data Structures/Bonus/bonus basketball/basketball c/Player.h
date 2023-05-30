# pragma once

# include <iostream>

class Player {
    protected:
    std::string name;
    std::string surname;

    public:
    // constructor
    Player(std::string name, std::string surname);
    // getters
    std::string getName();
    std::string getSurname();
    // methods
    virtual std::string getPlayerDescription();
};
