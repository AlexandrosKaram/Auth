# include "Course.h"

Course:: Course(std::string subject) {
    if (subject.length() < 3) 
        this->subject = "unknown";
    else    
        this->subject = subject;
}

void Course:: setProfessor(Professor professor) {
    this->professor = professor;
}

Professor Course:: getProfessor() {return professor;}

std::string Course:: getSubject() {return subject;}

bool Course:: isTaughtBy(std::string surname) {
    if (this->professor.getSurname() == surname)
        return true;
    else
        return false;
}