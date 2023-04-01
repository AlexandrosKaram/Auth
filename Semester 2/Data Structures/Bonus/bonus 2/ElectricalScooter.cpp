// implementation of class ElectricalScooter

#include <iostream>
#include "Scooter.h"
#include "ElectricalScooter.h"

using namespace std;

ElectricalScooter:: ElectricalScooter(){
    maxKM = 0;
    year = 0;
    chargingTime = 0;
}

ElectricalScooter:: ElectricalScooter(int maxKM, int year, int chargingTime){
    this->maxKM = maxKM;
    this->year = year;
    this->chargingTime = chargingTime;
}

ElectricalScooter:: ~ElectricalScooter(){}

double ElectricalScooter:: getPollutionScore(){
    return (double)chargingTime*300/365;
}

double ElectricalScooter:: getTaxes(){
    return Scooter::getTaxes()*0.8;
}

int ElectricalScooter:: getChargingTime(){
    return chargingTime;
}

void ElectricalScooter:: setChargingTime(int chargingTime){
    this->chargingTime = chargingTime;
}
