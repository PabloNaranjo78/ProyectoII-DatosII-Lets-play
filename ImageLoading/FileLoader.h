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
    /**
     * Carga la imagen
     */
    void load_image();
    /**
     * lee el string del CMD
     * @param cmd string
     * @return lo que se obtuvo del comando
     */
    string getCmdOutput(string cmd);
    /**
     * Devuelve un mensaje de error
     */
    void error();
    /**
     * devuelve la cantidad de divisiones
     */
    void getimagedivisions();
};


#endif //PROYECTO2_FILELOADER_H
