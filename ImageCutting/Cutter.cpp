
#include "Cutter.h"

void Cutter::getdivision(int div, int max) {
    cout<<"Added max " << max << endl;
    for(int a = 1; a <= div/2;a++){
        for (int b = 1; b <= div/2 ; b++) {
            if(a*b == div && abs(a-b) < max && a != div && a != 0 && b != div && b !=0){
                Vector2u div(a,b);
                this->divs = div;
                return;
            }
        }
    }
    getdivision(div,max+2);
}