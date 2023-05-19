# pragma once
// declaration of class myFile

// includes
#include <iostream>
#include <string>

class myFile {
    protected:
        char name[30];
    public:
        // constructors
        myFile();
        myFile(char*);
        // name getter
        char* getName();
        // name setter
        void setName();
        // methods
        bool exists();
        int countLines();
        int countChars();
        // operators
        
};