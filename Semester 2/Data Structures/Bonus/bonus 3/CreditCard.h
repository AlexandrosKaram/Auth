# pragma once

// initialization of class CreditCard

#include "Account.h"

class CreditCard: public Account{
    float LIMIT;
    public:
        CreditCard(char *description, float balance, float LIMIT)
            : Account(description, balance) {
                this->LIMIT = LIMIT;
            };
        bool withdraw(float);
};