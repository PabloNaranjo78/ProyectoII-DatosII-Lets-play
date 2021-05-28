//
// Created by david on 25/5/21.
//

#ifndef PROYECTO2_FILELOADER_H
#define PROYECTO2_FILELOADER_H
#include <cstdio>
#include <string>
using namespace std;

class FileLoader {

public:
    string image;
    int divisions;

    void load_image();
    string getCmdOutput(string cmd);
    void error();
    void getimagedivisions();
};


#endif //PROYECTO2_FILELOADER_H
