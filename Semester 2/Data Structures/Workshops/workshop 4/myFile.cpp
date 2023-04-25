// implementation of class myFile

#include <iostream>
#include <fstream>
#include <string>
#include "myFile.h"
using namespace std;

// constructor
myFile:: myFile(char *name){
    this->name = name;
}

// getter
char * myFile:: getName(){return name;}

// setter
void myFile:: setName(char *name){this->name = name;}

// methods
int myFile:: countLines(){ // counts the file's lines
    ifstream f;
    f.open(name); // open file
    if (f.is_open()) { // making sure file exists
        string line; // yep, use can directly use string in c++
        int cnt = 1; // starting from 1 so it counts blank line in the end
        while (getline(f, line)) {
            cnt++;
        }
        f.close();
        return cnt;
    }else{  // failed to locate file
        return 0;
    }
}