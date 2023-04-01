#ifndef ELECTRICALSCOOTER_H
#define ELECTRICALSCOOTER_H

// initialization of class ElectricalScooter

class ElectricalScooter: public Scooter{
    protected:
        int chargingTime;
    public:
        ElectricalScooter();
        ElectricalScooter(int,int,int);
        ~ElectricalScooter();
        double getPollutionScore();
        double getTaxes();
        int getChargingTime();
        void setChargingTime(int);        
};

#endif