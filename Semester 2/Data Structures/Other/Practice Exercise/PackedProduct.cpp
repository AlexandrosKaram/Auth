// Implement class PackedProduct.
#include "PackedProduct.h"
#include "Product.h"
#include "Date.h"

// constructors
PackedProduct:: PackedProduct(): Product(){};

PackedProduct:: PackedProduct(char *name, Date exp, int grams, bool open, int lifetime, Date opened): Product(){
    this->open = open;
    this->lifetime = lifetime;
    this->opened = opened; 
}
