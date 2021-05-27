#include <iostream>
#include "PathfindingA/PathfindingA.h"
//#include "GameManagment/Board.h"
#include "Graphics/BoardDisplay.h"
#include <SFML/Graphics.hpp>

//using namespace sf;
int main() {
    //PathfindingA * pathfindingA = new PathfindingA();
    //pathfindingA->getPath(6,7);
    //Board * board = new Board();
    //board->getPathPlayer();
    BoardDisplay * bpGame = new BoardDisplay();
    bpGame->runGame();


}
