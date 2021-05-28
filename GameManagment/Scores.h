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
    Scores();
    string getCurrentScore();
    void scoreFor(bool team);
    bool getMatchFinishedP1();
    bool getMatchFinishedP2();
};


#endif //PROYECTO2_SCORES_H
