// definition of class Controller
#include "Controller.h"
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

// saves an array of products in a text file
void Controller:: save(Product products[], const char *filename, int num) {
   ofstream f;
   f.open(filename);
   
   if (f.is_open()){    // making sure no errors occure
    for (int i=0;i<num;i++){
        f << products[i].getName() << endl;
        f << products[i].getPrice() << endl;
    }
   }
   f.close();
}

// loads products[] with the content of the file's lines
void Controller:: load(const char *filename, Product products[], int num){
    ifstream f;
    f.open(filename);

    if (f.is_open()){  // checking for errors
        string line;
        for (int i=0;i<num;i++){
            getline(f, line);  // copy line content to variable "line"
            int l = line.length();  // line length
            char *line_content = new char[l+1];  
            strcpy(line_content, line.c_str());  // converting string to chars to put it in line_content
            products[i].setName(line_content);
            // same for prices
            getline(f, line);
            products[i].setPrice(stof(line));  // converting string to float
        }
    }
    f.close();
}