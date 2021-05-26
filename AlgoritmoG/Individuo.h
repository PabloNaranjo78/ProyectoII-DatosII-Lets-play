

#ifndef PROYECTO2_INDIVIDUO_H
#define PROYECTO2_INDIVIDUO_H
#include <bits/stdc++.h>
using namespace std;

class Individuo{
public:
    string chromosome;
    int fitness;

    Individuo(string chromosome);
    void set_fitness(int fit);
};

#endif //PROYECTO2_INDIVIDUO_H
