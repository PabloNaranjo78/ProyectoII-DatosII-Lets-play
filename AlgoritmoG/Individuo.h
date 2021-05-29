

#ifndef PROYECTO2_INDIVIDUO_H
#define PROYECTO2_INDIVIDUO_H
#include <bits/stdc++.h>
using namespace std;

class Individuo{
public:
    string chromosome;
    int fitness;
    /**
     * Constructor de la clase
     * @param chromosome genoma
     */
    Individuo(string chromosome);
    /**
     * Le da un fitness al individuo
     * @param fit fitness
     */
    void set_fitness(int fit);
};

#endif //PROYECTO2_INDIVIDUO_H
