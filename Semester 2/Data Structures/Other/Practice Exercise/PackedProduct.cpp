// Implement class PackedProduct.
#include "PackedProduct.h"

// constructors
PackedProduct:: PackedProduct(){};

PackedProduct:: PackedProduct(char *name, Date exp, int grams, bool open, int lifetime, Date opened): Product(name, exp, grams){
    this->open = open;
    this->lifetime = lifetime;
    this->opened = opened; 
}

Date PackedProduct:: getExpiry(){
    if (open){
        return opened.add(lifetime);
    }else{
        return exp;
    }
}