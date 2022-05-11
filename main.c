#include <stdio.h>
#include "interface.h"
#include "game_player.h"
#include "stdlib.h"
#include "manual_solving.h"

int main() {
    int part=menu();
    switch(part){
        case 1: {
            int size = menuA1();
            int option = menuA2();
            switch(option){
                case 1:{
                    break;
                }
                case 2:{
                    break;
                }
                case 3:{
                    break;
                }
                case 4:{
                    break;
                }
            }
            break;
        }
        case 2: {

            break;
        }
        case 3: {

            break;
        }
    }

    int grid_static[4][4] =  {{1,0,0,1},{1,0,1,0},{0,1,1,0},{0,1,0,1}};

    int size=4;
    int** grid = malloc(sizeof(int*)*size);
    for(int i=0;i<size;i++){
        grid[i] = malloc(sizeof(int)*size);
        for(int j=0;j<size;j++) grid[i][j] = grid_static[i][j];
    }
    show_grid(enter_mask(size), size);


}
