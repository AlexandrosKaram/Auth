// implementation of class Vector

#include "Vector.h"
#include <cmath>
#include <iostream>
using namespace std;

const double pi = atan(1)*4;

Vector::Vector(){x=y=0;}

Vector::Vector(double a,double b){x=a;y=b;}

double Vector::GetX(){return x;}

double Vector::GetY(){return y;}

void Vector::SetX(double a){x=a;}

void Vector::SetY(double b){y=b;}

double Vector::magnitude(){
    return sqrt(pow(x,2)+pow(y,2));
}

double Vector::angle(){
    return atan(y/x);
}

double Vector::angleD(){
    return atan(y/x)*180/pi;    
}

void Vector::multiply(double f){
    SetX(x*f);
    SetY(y*f);
}

class Vector Vector::add(class Vector V){
    Vector A;
    A.SetX(x+V.x);
    A.SetY(y+V.y);
    return A; 
}

class Vector Vector::clone(){
    Vector A;
    A.SetX(x);
    A.SetY(y);
    return A;
}
