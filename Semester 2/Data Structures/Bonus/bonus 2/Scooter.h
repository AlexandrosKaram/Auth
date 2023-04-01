#ifndef SCOOTER_H
#define SCOOTER_H

// initialization of class Scooter

class Scooter{
    protected:
        int maxKM;
        int year;
    public:
        Scooter();
        Scooter(int,int);
        ~Scooter();
        int getYear();
        int getMaxKM();
        virtual double getPollutionScore();
        virtual double getTaxes();
};

#endif