// Implement class Product.
#include "Product.h"
#include "Date.h"

// constructors
Product:: Product(){};

Product:: Product(char* name, Date exp, int grams){
    this->name = name;
    this->exp = exp;
    this->grams = grams;
}

// getters
Date Product:: getExpiry(){return exp;}

char* Product:: Getname(){return name;}
