// Implement class Product.
#include "Product.h"

// constructors
Product:: Product(){};

Product:: Product(char* name, Date exp, int grams){
    strcpy(this->name, name);
    this->exp = exp;
    this->grams = grams;
}

// getters
Date Product:: getExpiry(){return exp;}

char* Product:: Getname(){return name;}
