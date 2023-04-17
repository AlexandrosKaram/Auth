// definition of class Product
#include "Product.h"

// constructor
Product:: Product(unsigned int id, char *name, float price){
    this -> id = id;
    this -> name = name;
    this -> price = price;
}

// destructor
Product:: ~Product(){};

// getters
char* Product:: getName(){return name;}

unsigned int Product:: getId(){return id;}

float Product:: getPrice(){return price;}

