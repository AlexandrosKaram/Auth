# pragma once
#include "Date.h"
#include "Product.h"
// Declare class PackedProduct.

class PackedProduct: public Product {
    bool open;
    int lifetime;
    Date opened;
    public:
        // constructors
        PackedProduct();
        PackedProduct(char *name, Date exp, int grams, bool open, int lifetime, Date opened);
};  