# pragma once
#include "Date.h"
// Declare class Product.

class Product{
    char *name;
    Date exp;
    int grams;
    public:
        // constructors
        Product();
        Product(char*, Date, int);
        // getters
        Date getExpiry();
        char* Getname();
}; 
