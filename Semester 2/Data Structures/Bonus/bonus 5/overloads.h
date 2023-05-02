#ifndef OVERLOADS_H
#define OVERLOADS_H

// overloading <<
#include "Product.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &os, Product &product) {
    os << product.getName() << " " << product.getPrice() << endl;
    return os;
}

#endif