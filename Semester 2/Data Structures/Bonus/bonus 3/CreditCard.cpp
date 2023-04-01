// implementation of class CreditCard

#include "CreditCard.h"

bool CreditCard:: withdraw(float amount){
    if (amount<=LIMIT){
        LIMIT -= amount;
        balance -= amount;
        return true;
    }
    return false;
}
