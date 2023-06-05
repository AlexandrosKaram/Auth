#pragma once
#include <iostream>

class Employee {
    protected:
    std::string surname;
    
    public:
    Employee(std::string surname);
    std::string getSurname();
};