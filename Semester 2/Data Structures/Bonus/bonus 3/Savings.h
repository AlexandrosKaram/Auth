# pragma once

// initialization of class Savings

#include "Account.h"

class Savings: public Account{
    int withdrawalsLeft;
    public:
        Savings(char *description, float balance)
            : Account(description, balance){
                withdrawalsLeft = 3;
            }
        bool withdraw(float amount);
};