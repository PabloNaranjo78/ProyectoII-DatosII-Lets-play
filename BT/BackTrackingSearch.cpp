//
// Created by pablo on 17/5/21.
//

#include <cstring>
#include "BackTrackingSearch.h"

#include "iostream"
using namespace std;

BackTrackingSearch::BackTrackingSearch() {

}

void BackTrackingSearch::printMatrix() {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void BackTrackingSearch::add(int _matrix[9][9]) {
    memcpy(matrix,_matrix,sizeof(int)*9*9 );
}

void BackTrackingSearch::searchOnePath() {
    searchStart();
    bool found = false;
    int x = startRow;
    int y = startColumn;
    while(!found){

        cout<<"--------"<<endl;
        cout<<x<<"-"<<y<<endl;

            if (matrix[y-1][x] == 0 and matrix[y-1][x] != 4 and y>0 and matrix[y-1][x] != 5){
                y-=1;
                matrix[y][x] = 1;
                list.addToList(matrix,"y-1");
            } else
            if (matrix[y][x-1] == 0 and matrix[y][x-1] != 4 and x >0 and matrix[y][x-1] != 5){
                x-=1;
                matrix[y][x] = 1;
                list.addToList(matrix,"x-1");
            }else
            if (matrix[y + 1][x] == 0 and matrix[y + 1][x] != 4 and matrix[y + 1][x] != 5) {
                y += 1;
                matrix[y][x] = 1;
                list.addToList(matrix,"y+1");
            } else if (matrix[y][x + 1] == 0 and matrix[y][x + 1] != 4 and matrix[y][x + 1] != 4) {
                x += 1;
                matrix[y][x] = 1;
                list.addToList(matrix, "x+1");
            }else if (closePath(x,y)){
                string lastMov = list.getLastMovement();
                memcpy(matrix,list.getLastElement()->data, sizeof(int)*9*9);
                cout<<"REVIERTE    -------  ------- ------"<<endl;
                matrix[y][x] = 5;
                list.replaceInALl(5,x,y);
                if (lastMov == "x+1"){
                    x-=1;
                } else if(lastMov == "y+1") {
                    y-=1;
                } else if (lastMov == "x-1"){
                    x+=1;
                } else if (lastMov == "y-1"){
                    y+=1;
                }

            //    break;

            }
      //  result+= "["+ to_string(x) +","+ to_string(y)+"],";
        if(matrix[y-1][x] == 2 or matrix[y][x-1] == 2 or matrix[y+1][x] == 2 or matrix[y][x+1] == 2){
            found = true;
        }// list.replaceInALl(9,4,0);
        printMatrix();
    }

}

void BackTrackingSearch::searchBestPath() {

}

void BackTrackingSearch::searchStart() {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9;j++){
            if (matrix[i][j] == 3){
                startRow = j;
                startColumn = i;
            }
        }
    }
    cout<<startRow<<" "<<startColumn<<endl;
}

bool BackTrackingSearch::closePath(int x, int y) {
    if ((matrix[y-1][x]==1 or matrix[y-1][x]==5 or matrix[y-1][x]==4 or matrix[y-1][x]==3)
        and (matrix[y+1][x] == 1 or matrix[y+1][x] == 5 or matrix[y+1][x] == 4 or matrix[y+1][x] == 3)
        and (matrix[y][x-1] == 1 or matrix[y][x-1] == 5 or matrix[y][x-1] == 4 or matrix[y][x-1] == 3)
        and (matrix[y][x+1] ==1 or matrix[y][x+1] ==5 or matrix[y][x+1] ==4 or matrix[y][x+1] ==3)){
            return true;
    } else{
        return false;
    }
}
