# pragma once
// Declare class Date.

class Date{
    int day,month,year;
    public:
        // constructors
        Date();
        Date(int, int, int);
        // getters
        int getDay();
        int getMonth();
        int getYear();
        // setters
        void setDay(int);
        void setMonth(int);
        void setYear(int);
        // methods
        int daysInMonth(int);
        void add(int);
        int diff(Date);
};