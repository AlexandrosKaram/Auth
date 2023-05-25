# pragma once
// declaration of class myFile

// includes
#include <iostream>
#include <string>

class myFile {
    protected:
        char* name;
    public:
        // constructors
        myFile();
        myFile(char*);
        // name getter
        char* getName();
        // name setter
        void setName(char*);
        // methods
        bool exists();
        int countLines();
        int countChars();
        // operators
        bool operator==(myFile file);
        myFile operator=(myFile file);
        myFile operator+=(myFile file);
};