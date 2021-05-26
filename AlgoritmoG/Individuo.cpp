#include "Individuo.h"


Individuo::Individuo(string chromosome) {
    this->chromosome = chromosome;
}

void Individuo::set_fitness(int fit) {
    this->fitness = fit;
}

