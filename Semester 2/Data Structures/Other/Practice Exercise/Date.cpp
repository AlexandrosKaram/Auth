// Implement class Date.
#include "Date.h"
#include <iostream>
using namespace std;

// constructors
Date:: Date(){};

Date:: Date(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}

// getters
int Date:: getDay(){return day;}

int Date:: getMonth(){return month;}

int Date:: getYear(){return year;}

// setters
void Date:: setDay(int day){this->day = day;}

void Date:: setMonth(int month){this->month = month;}

void Date:: setYear(int year){this->year = year;}

// methods
int Date:: daysInMonth(int m){
    switch (m){
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return 28;
        default:
            return 31;
    }
}

void Date:: add(int k){
    int dim = daysInMonth(month);
    if (k > dim-day){
        if (month==12){
            year++;
            month = 1;
        }else{
            month++;
        }
        day += k-dim;
    }else{
        day += k;
    }
}

int Date:: diff(Date b){
    return *this-b;
}

// operators

int Date:: operator-(Date b){
    int _dayA=0, _dayB=0;

    // Convert day and month to a number/365.
    for (int i=1;i<month;i++){
        _dayA += daysInMonth(i);
    }
    _dayA += day;

    for (int i=1;i<b.month;i++){
        _dayB += daysInMonth(i);
    }
    _dayB += b.day;

    return (b.year - year)*365 + _dayB - _dayA; 
}