#include "myFile.h"
#include <cstring>
#include <iostream>
#include <fstream>

myFile:: myFile() {
    this->name = NULL;
}

myFile:: myFile(char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

char* myFile:: getName() {
    return name;
}  

void myFile:: setName(char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

bool myFile:: exists() {
    std::fstream f;
    f.open(name, std::ios::in);
    
    return f.is_open();
}

int myFile:: countLines() {
    std::string s;
    int cnt = 0;
    std::ifstream file;

    file.open(name);
     
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, s);
            cnt++;
        }
    }
    file.close();
    return cnt;
}

int myFile:: countChars() {
    std::string s;
    int cnt = 0;
    int lines = 0;
    std::ifstream file;

    file.open(this->name);

    if (file.is_open()) {
        while (!file.eof()) {
            lines++;
            getline(file, s);
            cnt += s.length();
        }
        file.close();
    }
    return cnt+lines;
}

bool myFile:: operator==(myFile file) {
    std::ifstream f1, f2;
    f1.open(name);
    f2.open(file.getName());

    return (f2.is_open() && f1.is_open() &&
    this->countChars() == file.countChars() &&
    this->countLines() == file.countLines());
}

myFile myFile:: operator=(myFile file) {
    std::fstream f1, f2;
    f1.open(name, std::ios:: out);
    f2.open(file.getName(), std::ios:: in);

    if (f1.is_open() && f2.is_open()) {
        std::string s; 
        while (getline(f2, s)) {
            f1 << s << "\n";
        }
    }
    f1.close();
    f2.close();
    return *this;
}

myFile myFile:: operator+=(myFile file) {
    std::fstream f1, f2;
    f1.open(name, std::ios::app);
    f2.open(file.getName(), std::ios::in);

    if (f1.is_open() && f2.is_open()) {
        std:: string s;
        while (getline(f2, s)) {
            f1 << s << "\n";
        }
    }
    f1.close();
    f2.close();
    return *this;
}