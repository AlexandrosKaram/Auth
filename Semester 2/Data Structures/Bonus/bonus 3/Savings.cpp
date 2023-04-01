// implementation of class Savings

#include "Savings.h"

// actions

bool Savings:: withdraw(float amount){
    if (withdrawalsLeft && amount<=balance){
        withdrawalsLeft--;
        balance -= amount;
        return true;
    }
    return false;
}