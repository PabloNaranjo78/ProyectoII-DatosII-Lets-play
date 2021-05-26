
#ifndef PROYECTO2_GENETIC_H
#define PROYECTO2_GENETIC_H
#include <bits/stdc++.h>
#include "Individuo.h"

using namespace std;


class Genetic {

public:
    string genes ="0123456789";
    string target;

    int random_num(int start, int end);
    char mutated_genes();
    string create_gnome();
    Individuo aparear(Individuo par1, Individuo par2);
    int cal_fitness(Individuo individuo);
};


#endif //PROYECTO2_GENETIC_H
