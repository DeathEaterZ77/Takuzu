#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "manual_solving.h"

 int** enter_mask(int size){

     int** mask = malloc(sizeof(int*)*size);
     for(int i=0;i<size;i++){
         mask[i] = malloc(sizeof(int)*size);
         for(int j=0;j<size;j++){
             //char i_bis = (char)(i)+65;
             do {
                 printf("Enter the mask's value of the case %d%d : ", i, j);
                 scanf("%d", &mask[i][j]);
             } while(mask[i][j]!=0 && mask[i][j]!=1);
         }
     }
     return mask;
}

int** init_matrix(int size){
    int** matrix = malloc(sizeof(int*)*size);
    for(int i=0; i<size; i++) {
        matrix[i] = malloc(sizeof(int) * size);
        for(int j=0; j<size; j++){ matrix[i][j] = 0;}
    }
    return matrix;
}

int** generate_mask(int size){
    int** mask = init_matrix(size);
    int nb_cases = (int)(size*size*0.5);
    srand(time(NULL));
    while (nb_cases != 0) {
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if ((rand() % size == 1) && (mask[i][j]!=1)) {
                    mask[i][j] = 1;
                    nb_cases--;
                }
            }
        }
    }
    return mask;
}

int** apply_masktosolu(int** mask, int** solution, int size){
    int** grid_game = init_matrix(size);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if (mask[i][j]==1){ grid_game[i][j] = solution[i][j]; }
            else { grid_game[i][j] = -1;}
        }
    }
    return grid_game;
}