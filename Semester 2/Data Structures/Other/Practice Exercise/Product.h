# pragma once
// Declare class Product.

class Product{
    char name[20];
    int grams;
    Date exp;
    public:
        // constructors
        Product();
        Product(char*, Date, int);
        // getters
        Date getExpiry();
        char* getName();
        int getGrams();
        // setters
        void setExpiry(Date);
        void setName(char *);
        void setGrams(int);
}; 
