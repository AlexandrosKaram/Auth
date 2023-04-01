#ifndef STUDENT_H
#define STUDENT_H

// class declaration

class Person {
    int id;
    char surname[50];
public:
    Person();
    ~Person();
    Person(int, char*);
    void setId(int);
    void setSurname(char*);
    int getId();
    char* getSurname();
};

class Student : public Person {
    double fee;
public:
    Student();
    ~Student();
    void setFee(double);
    double getFee();
};

#endif // !STUDENT_H