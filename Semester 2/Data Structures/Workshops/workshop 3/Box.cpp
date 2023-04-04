// implementation of class Box

#include "Box.h"

// constructors
Box:: Box(){x=0;y=0;z=0;}

Box:: Box(double x, double y, double z){this->x = x; this->y = y; this->z = z;}

// getters
double Box:: getX(){return x;}

double Box:: getY(){return y;}

double Box:: getZ(){return z;}

// setters
void Box:: setX(double x){this->x = x;}

void Box:: setY(double y){this->y = y;}

void Box:: setZ(double z){this->z = z;}

// operators

// object with constant
Box& Box:: operator*(double n){
    x = x*n;
    y = y*n;
    z = z*n;
}

Box& Box:: operator/(double n){
    x = x/n;
    y = y/n;
    z = z/n;
}

Box& Box:: operator+(double n){
    x = x+n;
    y = y+n;
    z = z+n;
}

Box& Box:: operator-(double n){
    x = x+n;
    y = y+n;
    z = z+n;
}

// object with object
Box Box:: operator+(Box A){
    return Box(x+A.x, y+A.y + z+A.z);
}

Box Box:: operator-(Box A){
    return Box(x-A.x, y-A.y, z-A.z);
}

Box Box:: operator=(Box A){
    return A;
}

// boolean
bool Box:: operator==(Box A){
    if (x==A.x && y==A.y && z==A.z)
        return true;
    return false;
}

bool Box:: operator!=(Box A){
    if (x!=A.x || y!=A.y || z!=A.z)
        return true;
    return false;
}

// prefix increment
Box& Box::operator++()
{
   this->x++;
   this->y++;
   this->z++;
   return *this;
}

// postfix increment
Box Box::operator++(int)
{
   Point temp = *this;
   ++*this;
   return temp;
}

// prefix decrement
Box& Box::operator--()
{
   this->x--;
   this->y--;
   this->z--;
   return *this;
}

// postfix decrement
Point Point::operator--(int)
{
   Point temp = *this;
   --*this;
   return temp;
}

// assignment 
Box& Box::operator+=(int n){
    this->x+=n;
    this->y+=n;
    this->z+=n;
}

Box& Box::operator-=(int n){
    this->x-=n;
    this->y-=n;
    this->z-=n;
}

Box& Box::operator*=(int n){
    this->x*=n;
    this->y*=n;
    this->z*=n;
}

Box& Box::operator/=(int n){
    this->x/=n;
    this->y/=n;
    this->z/=n;
}

// output
ostream& operator<<(ostream& os, const Box& A){
    os << "length:" << A.x << ", width:" << A.y << ", height:" << A.z;
}
