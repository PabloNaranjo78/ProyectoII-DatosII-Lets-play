#include <iostream>

#include "../Graphics/Menu.h"
#include "../Graphics/Menu.cpp"
using namespace std;
using namespace sf;



int main() {
    //PathfindingA * pathfindingA = new PathfindingA();
    //pathfindingA->getPath(6,7);
    //Board * board = new Board();
    //board->getPathPlayer();
    //Window
    Menu* menu = new Menu();
    menu->run();
}






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




