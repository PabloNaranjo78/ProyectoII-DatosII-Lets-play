#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "rapidjson/document.h"
#include <string>
#include <iostream>


#include "../AlgoritmoG/Genetic.h"
#include "../AlgoritmoG/Genetic.cpp"

using namespace sf;
using namespace std;
using namespace rapidjson;

// Overloading < operadaor
bool operator<(const Individuo &ind1, const Individuo &ind2)
{
    return ind1.fitness < ind2.fitness;
}

/**
 * @brief jsonReviever se encarga de desempaquetar el mensaje JSON del cliente
 * @param packet paquete que envio el cliente
 * @return un documento donde se pueden extraer las variables
 */
Document jsonReceiver(Packet packet)
{
    string pet;
    Document petD;

    packet >> pet;
    cout << pet << endl;
    const char* petChar = pet.c_str();
    petD.Parse(petChar);

    return petD;
}
/**
 * @brief jsonSender se encarga de formatear los mensajes de servidor-> cliente
 * @param memory espacio de memoria alocada
 * @param value valor de la variable
 * @param variable nombre de la variable
 * @param ref cantiad de referencias
 * @return un string en formato JSON listo para enviar
 */
string jsonSender(string type, string gnome)
{
    string jsonStr = R"({"type":")"+ type + R"(","gnome":")" + gnome + "\"}";
    return jsonStr;
}


void run_geneticAlgorithm(TcpSocket* socket, Genetic* gen){
    #define POPULATION_SIZE 100
    Packet packetS;
    string json;

    srand((unsigned)(time(0)));
    cout<<gen->genes.size()<<endl;
    // current generation
    int generation = 0;

    vector<Individuo> population;
    bool found = false;

    // create initial population
    for(int i = 0;i<POPULATION_SIZE;i++)
    {
        string gnome = gen->create_gnome();
        Individuo tmp(gnome);
        tmp.fitness = gen->cal_fitness(tmp);
        population.push_back(tmp);
    }
    json = jsonSender("gnome",population.begin()->chromosome);
    cout << json<<endl;
    packetS << json;//empaqueta el json
    socket->send(packetS);//manda el json a cliente
    packetS.clear();//vacia los packets
    json = "";
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
            int r = gen->random_num(0, 50);
            Individuo parent1 = population[r];
            r = gen->random_num(0, 50);
            Individuo parent2 = population[r];
            Individuo offspring = gen->aparear(parent1,parent2);
            offspring.fitness = gen->cal_fitness(offspring);
            new_generation.push_back(offspring);
        }
        population = new_generation;
        cout<< "Generation: " << generation << "\t";
        cout<< "String: "<< population[0].chromosome <<"\t";
        cout<< "Fitness: "<< population[0].fitness << "\n";
        //escribir XML

        json = jsonSender("gnome",population[0].chromosome);
        cout << json<<endl;
        packetS << json;//empaqueta el json
        socket->send(packetS);//manda el json a cliente
        packetS.clear();//vacia los packets

        generation++;
    }
    cout<< "Generation: " << generation << "\t";
    cout<< "String: "<< population[0].chromosome <<"\t";
    cout<< "Fitness: "<< population[0].fitness << "\n";

    //json = jsonSender("gnome",population[0].chromosome);
    json = jsonSender("gnome",population[0].chromosome);
    cout << json <<endl;
    packetS << json;//empaqueta el json
    socket->send(packetS);//manda el json a cliente
    packetS.clear();//vacia los packets



}

int main() {
    IpAddress ip = IpAddress::getLocalAddress();//ipaddres del socket
    TcpSocket socket;//socket a conectar
    char connectionType, mode;//varles de conexion
    bool done = false;
    Packet packetR;//packets para recibir y mandar JSON
    size_t received;
    Document petition;//petition del packetR
    string json;//json que se manda
    Genetic genetic;


    TcpListener listener;//listener del server
    listener.listen(8080);//asigarle el puerto 8080
    listener.accept(socket);//recibe la conexion del socket de cliente



    while (!done) {
        Event event;// revisar eventos en la pantalla
        if (event.key.code == Keyboard::Escape)//cerrar el server
            done = true;

        socket.receive(packetR);

        if (packetR.getData() == NULL) {//si no recibe nada el servidor no actua
            cout << "No message received yet" << endl;
            done = false;
        }
        else {
            petition = jsonReceiver(packetR);//desempaqueta el JSON
            //separa el json en variable
            string type = petition["type"].GetString();
            string action = petition["action"].GetString();

            if(type == "startG"){
                string target = petition["target"].GetString();
                genetic.target = target;
                run_geneticAlgorithm(&socket,&genetic);
            }
            else if (type == "startPathF"){

            }
            else if (type == "startBackT"){

            }
        }

    }
    return 0;
}
