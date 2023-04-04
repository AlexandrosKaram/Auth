// Implement class Date.
#include "Date.h"
#include <iostream>

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
    if (m==2)
        return 28;
    else if (m%2)
        return 31;
    else 
        return 30;
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
    int diff, _dayA, _dayB;

    // Convert day and month to a number/365.
    for (int i=1;i<_dayA;i++){
        _dayA += daysInMonth(i);
    }
    _dayA += day;

    for (int i=1;i<_dayB;i++){
        _dayB += daysInMonth(i);
    }
    _dayB += b.day;

    // Add the years apart too
    diff = _dayB-_dayA + (b.year-year)*365;

    return diff;
}