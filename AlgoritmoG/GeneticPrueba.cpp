#include <iostream>
#include <vector>
#include "Genetic.h"
#include "Genetic.cpp"

// Number of individuals in each generation
#define POPULATION_SIZE 100

// Overloading < operadaor
bool operator<(const Individuo &ind1, const Individuo &ind2)
{
    return ind1.fitness < ind2.fitness;
}

int main(){

    Genetic gen;
    gen.target = "0123456789";
    srand((unsigned)(time(0)));

    // current generation
    int generation = 0;

    vector<Individuo> population;
    bool found = false;

    // create initial population
    for(int i = 0;i<POPULATION_SIZE;i++)
    {
        string gnome = gen.create_gnome();
        Individuo tmp(gnome);
        tmp.fitness = gen.cal_fitness(tmp);
        population.push_back(tmp);
    }
    cout<<"Creo population"<<endl;
    cout<< population.begin()->chromosome<<endl;
    while(! found)
    {
        // sort the population in increasing order of fitness score
        sort(population.begin(), population.end());

        // if the individual having lowest fitness score ie.
        // 0 then we know that we have reached to the target
        // and break the loop
        if(population[0].fitness <= 0)
        {
            found = true;
            break;
        }

        // Otherwise generate new offsprings for new generation
        vector<Individuo> new_generation;

        // Perform Elitism, that mean 10% of fittest population
        // goes to the next generation
        int s = (10*POPULATION_SIZE)/100;
        for(int i = 0;i<s;i++)
            new_generation.push_back(population[i]);


        // From 50% of fittest population, Individuals
        // will mate to produce offspring
        s = (90*POPULATION_SIZE)/100;
        for(int i = 0;i<s;i++)
        {
            int len = population.size();
            int r = gen.random_num(0, 50);
            Individuo parent1 = population[r];
            r = gen.random_num(0, 50);
            Individuo parent2 = population[r];
            Individuo offspring = gen.aparear(parent1,parent2);
            offspring.fitness = gen.cal_fitness(offspring);
            new_generation.push_back(offspring);
        }
        population = new_generation;
        cout<< "Generation: " << generation << "\t";
        cout<< "String: "<< population[0].chromosome <<"\t";
        cout<< "Fitness: "<< population[0].fitness << "\n";

        generation++;
    }
    cout<< "Generation: " << generation << "\t";
    cout<< "String: "<< population[0].chromosome <<"\t";
    cout<< "Fitness: "<< population[0].fitness << "\n";
    return 0;
}






