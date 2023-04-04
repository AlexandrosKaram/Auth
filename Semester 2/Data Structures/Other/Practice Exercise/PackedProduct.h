# pragma once
// Declare class PackedProduct.

class PackedProduct: public Product {
    bool open;
    int lifetime;
    Date d;
    public:
        // constructors
        PackedProduct();
        PackedProduct(char*, Date, int, bool, int, Date);
        // getters
        bool getOpen();
        int getLifetime();
        Date getD();
        // setters
        void setOpen(bool);
        void setLifetime(int);
        void setD(Date);
};  