// definition of class Controller
#include "Controller.h"
#include <fstream>
#include <string>
#include "overloads.h"

// saves an array of products in a text file
void Controller:: save(Product products[], const char *filename, int num) {
   ofstream f;
   f.open(filename);
   
   if (f.is_open()){    // making sure no errors occure
    for (int i=0;i<num;i++){
        f << products[i];
    }
   }
   f.close();
}

void Controller:: load(const char *filename, Product products[], int num){
    ifstream f;
    f.open(filename);

    if (f.is_open()){
        string line;
        for (int i=0;i<num;i++){
            getline(f, line);
            int l = line.length(); // length of line
            char *
        }
    }
}