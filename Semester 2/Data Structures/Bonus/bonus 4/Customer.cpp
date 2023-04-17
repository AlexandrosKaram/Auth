// definition of class Customer
#include "Customer.h"

// constructor
Customer:: Customer(char *username){
    this -> username = username;
    for (int i=0;i<3;i++){
        shoppingCart[i] = NULL;
    }
}

// destructor
Customer:: ~Customer(){}

// getters
char *Customer:: getUsername(){return username;}

// methods
int Customer:: getNumberOfProducts(){
    int cnt = 0; // counter
    for (int i=0;i<3;i++){ // traverse through cart items to see if they exist
        if (shoppingCart[i] != NULL)
            cnt++;  // increase counter
    }
    return cnt;
}

bool Customer:: addProduct(Product *product){
    for (int i=0;i<3;i++){
        if (shoppingCart[i] == NULL){
            shoppingCart[i] = product;
            return true;
        }
    }
    return false;
}

float Customer:: getTotalCost(){
    float total=0;
    for (int i=0;i<3;i++){
        if (shoppingCart[i] != NULL){
            total += shoppingCart[i]->getPrice();
        }
    }
    return total;
}

Product* Customer:: findProductById(unsigned int id, int &pos){
    for (int i=0;i<3;i++){
        if (shoppingCart[i] != NULL && shoppingCart[i]->getId() == id){
            pos = i;
            return shoppingCart[i];
        }
    }
    pos = -1;
    return NULL;
}

bool Customer:: removeProduct(unsigned int id){
    for (int i=0;i<3;i++){
        if (shoppingCart[i] != NULL && shoppingCart[i]->getId() == id){
            shoppingCart[i] = NULL;
            return true;
        }
    }
    return false;
}