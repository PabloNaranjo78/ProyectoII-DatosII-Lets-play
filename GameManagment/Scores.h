//
// Created by anthony on 18/5/21.
//

#ifndef PROYECTO2_SCORES_H
#define PROYECTO2_SCORES_H

#include <string>
#include <iostream>

using namespace std;

class Scores {
private:
    int scorePlayer1;
    int scorePlayer2;
public:
    /**
     * Constructor de la clase
     */
    Scores();
    /**
     * Obtiene el marcador actual en formato de string
     * @return string del marcador
     */
    string getCurrentScore();
    /**
     * Anota para el jugador que indique la entrada
     * @param team valor de verdad que indica el equipo
     */
    void scoreFor(bool team);
    /**
     * Indica si el juego ha acabado a favor del jugador
     * @return valor de verdad que indica si el jugador gana
     */
    bool getMatchFinishedP1();
    /**
     * Indica si el juego ha acabado a favor de la computadora
     * @return valor de verdad que indica si la computadora gana
     */
    bool getMatchFinishedP2();
};


#endif //PROYECTO2_SCORES_H
