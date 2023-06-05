#include "overloads.h"

std::ostream& operator<<(std::ostream &os, Course &course) {
    os << course.getSubject() << "-" << course.getProfessor().getSurname();
}

bool operator==(Professor p1, Professor p2) {
    return (p1.getPublishes() == p2.getPublishes());
}