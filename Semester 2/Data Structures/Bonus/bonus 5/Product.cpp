// definition of class Product

#include "Product.h"
#include <iostream>
#include <cstring>
using namespace std;

// default constructor
Product:: Product() {
    name = new char[1];
    name[0] = ' ';
    price = 0;
}

// constructor with parameters
Product:: Product(const char *name, float price){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->price = price;
}

// destructor
Product:: ~Product() {
    delete[] name;
}

// getters
char * Product:: getName(){return name;}
float Product:: getPrice(){return price;}

// setters
void Product:: setName(const char *name){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

void Product:: setPrice(float price){
    this->price = price;
}