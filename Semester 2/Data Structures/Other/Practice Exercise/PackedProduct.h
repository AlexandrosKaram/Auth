# pragma once
// Declare class PackedProduct.

class PackedProduct: public Product {
    bool open;
    int lifetime;
    Date opened;
    public:
        // constructors
        PackedProduct();
        PackedProduct(char*, Date, int, bool, int, Date);
};  