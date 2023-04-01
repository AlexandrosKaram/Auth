// class implementation

#include <iostream>
#include <string.h>
#include "Student.h"

using namespace std;

// implementation of parent class Person

Person:: Person(){};

Person:: ~Person(){cout<<"destructor in Person"<<endl;}

Person:: Person(int id, char* surname) {
    setId(id);
    setSurname(surname);
}

void Person:: setId(int id) {
    this->id = id;
}

void Person:: setSurname(char* surname) {
    strcpy(this->surname, surname);
}

int Person::getId() {
    return id;
}

char *Person:: getSurname() {
    return surname;
}

// implementation of child class Student

Student:: Student(){};

Student:: ~Student(){cout<<"destructor in Student"<<endl;}

void Student::setFee(double fee) {
    this->fee = fee;
}

double Student::getFee() {
    return fee;
}