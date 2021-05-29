
#ifndef PROYECTO2_GENETIC_H
#define PROYECTO2_GENETIC_H
#include <bits/stdc++.h>
#include "Individuo.h"

using namespace std;


class Genetic {

public:
    string genes ="0123456789abcdefghijklmno";
    string target;

    /**
     * Genera numero random
     * @param start limite inferior
     * @param end limite superios
     * @return el numero generado
     */
    int random_num(int start, int end);
    /**
     * selecciona cual gen quiere mutar
     * @return gen
     */
    char mutated_genes();
    /**
     * Crea el ADN de cada individuo
     * @return el ADN del individuo
     */
    string create_gnome();
    /**
     * Aparea dos individuos
     * @param par1 padre 1
     * @param par2 padre 2
     * @return ADN del hijo
     */
    Individuo aparear(Individuo par1, Individuo par2);
    /**
     * calcula el fitness de cada individuo
     * @param individuo
     * @return fitnes del individuo
     */
    int cal_fitness(Individuo individuo);
};


#endif //PROYECTO2_GENETIC_H
