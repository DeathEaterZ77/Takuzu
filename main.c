#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "manual_solving.h"

int main() {
    int part=menu();
    switch(part){
        case 1: {
            int size = menuA1();
            getchar();
            int option = menuA2();
            switch(option){
                case 1:{
                    int** manual_mask = enter_mask(size);
                    printf("Your entered mask :\n");
                    show_grid(manual_mask,size);
                    break;
                }
                case 2:{
                    int** auto_mask = generate_mask(size);
                    printf("Your generated mask :\n");
                    show_grid(auto_mask,size);
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
        default : printf("You have to choose between 1 and 3..."); break;
    }

   /* int grid_static[4][4] =  {{1,0,0,1},{1,0,1,0},{0,1,1,0},{0,1,0,1}};

    int size=4;
    int** grid = malloc(sizeof(int*)*size);
    for(int i=0;i<size;i++){
        grid[i] = malloc(sizeof(int)*size);
        for(int j=0;j<size;j++) grid[i][j] = grid_static[i][j];
    }*/



}
