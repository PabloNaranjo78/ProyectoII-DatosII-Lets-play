#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "rapidjson/document.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;
using namespace rapidjson;

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
string jsonSender(string memory, string value, string variable,string ref)
{
    string type = "RLV";
    string jsonStr = R"({"memory":")"+ memory + R"(","type":")" + type + R"(","value":")" + value + R"(","variable":")" + variable + R"(","ref":")" + ref + "\"}";
    return jsonStr;
}


int main() {
    IpAddress ip = IpAddress::getLocalAddress();//ipaddres del socket
    TcpSocket socket;//socket a conectar
    char connectionType, mode;//varles de conexion
    bool done = false;
    Packet packetR, packetS;//packets para recibir y mandar JSON
    size_t received;
    Document petition;//petition del packetR
    string json;//json que se manda



    TcpListener listener;//listener del server
    listener.listen(8080);//asigarle el puerto 8080
    listener.accept(socket);//recibe la conexion del socket de cliente
    mode = 'r';


    while (!done) {
        Event event;// revisar eventos en la pantalla
        if (event.key.code == Keyboard::Escape)//cerrar el server
            done = true;

        socket.receive(packetR);

        if (packetR.getData() == NULL)//si no recibe nada el servidor no actua
            cout << "No message received yet" << endl;
            done = false;

        else {
            petition = jsonReceiver(packetR);//desempaqueta el JSON
            //separa el json en variables
            string value = petition["value"].GetString();
            string type = petition["type"].GetString();
            string variable = petition["variable"].GetString();

        }

        packetS << json;//empaqueta el json
        socket.send(packetS);//manda el json a cliente
        packetS.clear();//vacia los packets
        packetR.clear();
        json = "";//vacia el log

    }
    return 0;
}
