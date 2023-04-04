# pragma once
#include "Date.h"
#include <cstring>
// Declare class Product.

class Product{
    char name[20];
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
