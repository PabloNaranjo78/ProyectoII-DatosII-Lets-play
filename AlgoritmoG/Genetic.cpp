
#include "Genetic.h"
#include "Individuo.h"
#include "Individuo.cpp"

int Genetic::random_num(int start, int end) {
    int range = (end-start)+1;
    int random_int = start+(rand()%range);
    return random_int;
}

char Genetic::mutated_genes() {
    int len = this->target.size();
    int r = random_num(0, len-1);
    return this->genes[r];
}


string Genetic::create_gnome() {
    int len = this->target.size();
    string gnome = "";
    string dna = "";
    for(int i = 0;i<len;i++) {
        dna += mutated_genes();
        size_t found = gnome.find(dna);
        if(found != string::npos){
            len++;
        }
        else{
            gnome += dna;
        }
        dna = "";
    }
    return gnome;
}


Individuo Genetic::aparear(Individuo par1, Individuo par2){
    // chromosome for offspring
    string child_chromosome = "";

    int len = par1.chromosome.size();
    for(int i = 0;i<len;i++) {
        // random probability
        float p = random_num(0, 100) / 100;

        // if prob is less than 0.45, insert gene
        // from parent 1
        if (p < 0.45){
            size_t found = child_chromosome.find(par1.chromosome[i]);
            if(found == string::npos){
                child_chromosome += par1.chromosome[i];
            }
            else{
                child_chromosome += mutated_genes();
            }

        }
            // if prob is between 0.45 and 0.90, insert
            // gene from parent 2
        else if(p < 0.90){
            size_t found = child_chromosome.find(par2.chromosome[i]);
            if(found == string::npos){
                child_chromosome += par2.chromosome[i];
            }
            else{
                child_chromosome += mutated_genes();
            }
        }

            // otherwise insert random gene(mutate),
            // for maintaining diversity
        else
            child_chromosome += mutated_genes();
    }

    // create new Individual(offspring) using
    // generated chromosome for offspring
    Individuo hijo(child_chromosome);
    hijo.fitness = cal_fitness(hijo);
    return hijo;
}

int Genetic::cal_fitness(Individuo ind) {
    int len = this->target.size();
    int fitness = 0;
    for(int i = 0;i<len;i++)
    {
        if(ind.chromosome[i] != this->target[i])
            fitness++;
    }
    return fitness;
}
