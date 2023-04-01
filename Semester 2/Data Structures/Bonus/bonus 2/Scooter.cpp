// implementation of class Scooter

#include <iostream>
#include "Scooter.h"

using namespace std;

Scooter:: Scooter(){
    maxKM = 0;
    year = 0;
}

Scooter:: ~Scooter(){}

Scooter:: Scooter(int maxKM, int year){
    this->maxKM = maxKM;
    this->year = year;
}

int Scooter:: getYear(){
    return year;
}

int Scooter:: getMaxKM(){
    return maxKM;
}

double Scooter:: getPollutionScore(){
    return (double)maxKM*250/365;
}

double Scooter:: getTaxes(){
    return (2022-year)*12.5;
}