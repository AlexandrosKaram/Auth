# pragma once
# include "Professor.h"

class Course {
    protected:
    std::string subject;
    Professor professor;

    public:
    Course(std::string subject);
    void setProfessor(Professor professor);
    Professor getProfessor();
    std::string getSubject();
    bool isTaughtBy(std::string surname);
};