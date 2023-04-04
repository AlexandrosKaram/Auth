# pragma once

#include <iostream>
using namespace std;

// Declare class Box.
class Box {
    public:
        double x,y,z; // dimensions
        // constructors
        Box();
        Box(double, double, double);
        
        // getters
        double getX();
        double getY();
        double getZ();
        
        // setters
        void setX(double);
        void setY(double);
        void setZ(double);
        
        // operators
        
        // object with constant
        Box& operator*(double);
        Box& operator/(double);
        Box& operator+(double);
        Box& operator-(double);
        
        // object with object
        Box operator+(Box); 
        Box operator-(Box); 
        Box operator=(Box); 

        // boolean
        bool operator==(Box);
        bool operator!=(Box);

        // prefix and postfix increment operators
        Box& operator++(); 
        Box operator++(int);     

        // prefix and postfix decrement operators
        Box& operator--(); 
        Box operator--(int); 

        // assignment
        Box& operator+=(int);
        Box& operator-=(int);
        Box& operator*=(int);
        Box& operator/=(int);

        // output
        friend ostream& operator<<(ostream& os, const Box& A);
};