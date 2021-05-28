#include <iostream>
#include "PathfindingA/PathfindingA.h"
//#include "GameManagment/Board.h"
#include "Graphics/BoardDisplay.h"
#include "BT/BackTrackingSearch.h"
#include <SFML/Graphics.hpp>

//using namespace sf;
int main() {
    //PathfindingA * pathfindingA = new PathfindingA();
    //pathfindingA->getPath(6,7);
    //Board * board = new Board();
    //board->getPathPlayer();
    BoardDisplay * bpGame = new BoardDisplay();
    bpGame->runGame();

//    int num[9][9]={
//            {4,4,4,4,4,4,4,4,4},
//            {4,0,0,0,2,0,0,0,4},
//            {4,0,0,0,0,0,0,0,4},
//            {4,0,4,4,4,4,4,4,4},
//            {4,0,0,0,0,0,0,0,4},
//            {4,0,0,0,0,0,0,0,4},
//            {4,0,0,0,0,0,0,0,4},
//            {4,0,0,0,0,0,3,0,4},
//            {4,4,4,4,4,4,4,4,4},
//    };
//    BackTrackingSearch backTrackingSearch;
//    backTrackingSearch.add(num);
//    backTrackingSearch.searchOnePath();
//    cout<<endl;
//    backTrackingSearch.printMatrix();



}
