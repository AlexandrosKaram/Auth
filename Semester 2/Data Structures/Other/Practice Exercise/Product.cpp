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

char* Product:: getName(){return name;}

int Product:: getGrams(){return grams;}

// setters
void Product:: setExpiry(Date exp){this->exp = exp;}

void Product:: setName(char *name){this->name = name;}

void Product:: setGrams(int grams){this->grams = grams;}


