#pragma once

// declaration of class myFile
class myFile{
    protected:
        char *name; // name of the file
    public:
        // constructor
        myFile(char *name);

        // getter - setter
        char * getName();
        void setName(char *name);

        // methods
        int countLines();
};