#include "solutions_grids.h"
#include "stdio.h"
#include "stdlib.h"


int** get_tab(int size){

    int static_solu4[4][4] = {{1,0,0,1},{1,0,1,0},{0,1,1,0},{0,1,0,1}};


    int static_solu8[8][8] = {{0, 1, 0, 1, 1, 0, 0, 1},
                              {1, 0, 0, 1, 0, 0, 1, 1},
                              {0, 1, 1, 0, 0, 1, 1, 0},
                              {1, 1, 0, 0, 1, 1, 0, 0},
                              {0, 0, 1, 1, 0, 0, 1, 1},
                              {0, 1, 0, 1, 1, 0, 1, 0},
                              {1, 0, 1, 0, 1, 1, 0, 0},
                              {1, 0, 1, 0, 0, 1, 0, 1}};

    int** tab_solu = malloc(sizeof(int)*size);
    for(int i=0; i<size; i++){
        tab_solu[i] = malloc(sizeof(int)*size);
        for (int j=0; j<size; j++){
            if(size==4){ tab_solu[i][j] = static_solu4[i][j];}
            else if(size==8){ tab_solu[i][j] = static_solu8[i][j];}
        }
    }
    return tab_solu;
}