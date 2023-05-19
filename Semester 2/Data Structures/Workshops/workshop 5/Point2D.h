# pragma once
// class Point2D

// includes
#include <iostream>
#include <cmath>
using namespace std;

// declaration of class
class Point2D {
private:
    int x,y;
public:
    Point2D();   // constructor
    ~Point2D();   // destructor
    int getX();   // getter for x
    int getY();   // getter for y
    void setX(int x);   // setter for x
    void setY(int y);   // setter for y
    // operators
    bool operator>(Point2D& p);
    bool operator<(Point2D& p);
    void operator=(Point2D& p);
    // personal functions
    float d();   // returns distance from (0,0)
};

// definition of class
Point2D:: Point2D() {   // constructor
    x = 0;
    y = 0;
}

Point2D:: ~Point2D() {}   // destructor

int Point2D:: getX() {return x;}   // getter for x

int Point2D:: getY() {return y;}   // getter for y

void Point2D:: setX(int x) {this->x = x;}   // setter for x

void Point2D:: setY(int y) {this->y = y;}   // setter for y

// operators
bool Point2D:: operator>(Point2D& p) {
    return d() > p.d();
}

bool Point2D:: operator<(Point2D& p) {
    return d() < p.d();
}

void Point2D:: operator=(Point2D& p) {
    this->x = p.x;
    this->y = p.y;
}

// personal functions
float Point2D:: d() {
    return sqrt(pow(x,2) + pow(y,2));
}