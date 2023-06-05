#pragma once
#include "Employee.h"

class Professor : public Employee {
    protected:
    int publishes;

    public:
    Professor() : Employee() {};
    Professor(std::string surname);
    int getPublishes();
    void setPublishes(int publishes);
};  