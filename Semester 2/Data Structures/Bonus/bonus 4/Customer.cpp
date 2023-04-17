// definition of class Customer
#include "Customer.h"

// constructor
Customer:: Customer(char *username){
    this -> username = username;
}

// destructor
Customer:: ~Customer(){}

// getters
char *Customer:: getUsername(){return username;}

int getNumberOfProducts(){
    
}
