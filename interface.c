#include "interface.h"
#include <stdio.h>


int menu(){
    int part;
    printf("-------------------- TAKUZU'S GAME --------------------\n"
           "                         MENU                          \n"
           "Make a choice :\n\t1 - Play by solving a grid\n\t2 - Solve automatically a grid\n\t3 - Generate a grid\n\t4 - Exit\n");
    scanf("%d",&part);
    return part;
}

int menuA1(){
    int size;
    printf("-------------------- LET'S PLAY --------------------\n"
           "Choose the size of the grid :\n\t1 - Easy : 4x4\n\t2 - Intermediate : 8x8\n");
    scanf("%d",&size);
    return size;
}

int menuA2(){
    int option;
    printf("How do you want to play ? \n"
           "\t1 - Enter a mask manually\n\t2 - Generate automatically a mask\n\t3 - Play\n\t4 - Return to menu\n");
    scanf("%d",&option);
    return option;
}

void show_grid(int** grid,int size){
    int i,j;
    char letter='A';
    printf("\n   ");
    for(j=0;j<size;j++) printf("%d  ",j);
    printf("\n");
    for(i=0;i<size;i++){
        printf("%c  ",letter);
        letter+=1;
        for(j=0;j<size;j++){
            if(grid[i][j]==-1)printf("   ");
            else printf("%d  ",grid[i][j]);
        }
        printf("\n");
    }
}




void grid(int size,int** grid_game,int** mask,int** solution){
    char letter='A';
    for(int i=0; i<size; i++){

        for(int j=0; j<size; j++){

        }

    }
}

