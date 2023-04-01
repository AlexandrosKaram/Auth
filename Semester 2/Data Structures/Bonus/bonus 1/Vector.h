#ifndef VECTOR_H
#define VECTOR_H

// initialization of class Vector

class Vector{
    private:
        double x,y;
    public:
        Vector();
        Vector(double a,double b);
        double GetX();
        double GetY();
        void SetX(double a);
        void SetY(double b);
        double magnitude();
        double angle();
        double angleD();
        void multiply(double f);
        class Vector add(class Vector V);
        class Vector clone();
};

#endif