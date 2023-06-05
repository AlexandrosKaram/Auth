#include "Employee.h"

Employee:: Employee(std::string surname) {
    this->surname = surname;
}

std::string Employee:: getSurname() {
    return surname;
}