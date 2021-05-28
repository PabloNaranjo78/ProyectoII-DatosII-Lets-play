//
// Created by anthony on 18/5/21.
//

#include "Scores.h"

Scores::Scores() {
    this->scorePlayer1 = 0;
    this->scorePlayer2 = 0;
}

string Scores::getCurrentScore() {
    return to_string(this->scorePlayer1)+":"+to_string(this->scorePlayer2);
}

void Scores::scoreFor(bool team) {
    if (team){
        this->scorePlayer1++;
    }else{
        this->scorePlayer2++;
    }
}


bool Scores::getMatchFinishedP1() {
    if (this->scorePlayer1 > 2){
        return true;
    }
    return false;
}

bool Scores::getMatchFinishedP2() {
    if (this->scorePlayer2 > 2){
        return true;
    }
    return false;
}