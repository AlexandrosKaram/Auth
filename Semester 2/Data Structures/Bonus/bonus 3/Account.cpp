// implementation of class Account

#include "Account.h"
#include <string>

// constructors with one and two args

Account:: Account(char *description){
    this->description = description;
    balance = 0;
}

Account:: Account(char *description, float balance){
    this->description = description;
    this->balance = balance;
}

// actions

bool Account:: withdraw(float amount){
    if (amount<=balance){
        balance -= amount;
        return true;
    }
    return false;
}

bool Account:: deposit(float amount){
    if (amount>0){
        balance += amount;
        return true;
    } 
    return false;
}

// getters

float Account:: getBalance(){
    return balance;
}

char * Account:: getDescription(){
    return description;
}