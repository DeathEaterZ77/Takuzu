#include "interface.h"
#include <stdio.h>


int menu(){
    int part;
    setbuf(stdout, 0);
    printf("-------------------- TAKUZU'S GAME --------------------\n"
           "                         MENU                          \n"
           "Make a choice :\n\t1 - Play by solving a grid\n\t2 - Solve automatically a grid\n\t3 - Generate a grid\n\t4 - Exit\n");
    scanf("%d",&part);
    return part;
}

int menuA1(){
    int size;
    do{
    printf("-------------------- LET'S PLAY --------------------\n"
           "Choose the size of the grid :\n\t1 - Easy : 4x4\n\t2 - Intermediate : 8x8\n");
    scanf("%d",&size); } while(size!=1 && size!=2);
    switch(size){
        case 1: size=4; break;
        case 2: size=8; break;
    }
    return size;
}

int menuA2(){
    int option;
    do{
    printf("How do you want to play ? \n\t1 - Enter a mask manually\n\t2 - Generate automatically a mask\n\t3 - Play\n\t4 - Return to menu\n");
    scanf("%d",&option);}
    while(option!=1 && option!=2 && option!=3 && option!=4);
    return option;
}


int menuB1(){
    int size;
    do{
        printf("-------------------- AUTO-SOLVE --------------------\n"
               "Choose the size of the grid to solve:\n\t1 - 4x4\n\t2 - 8x8\n");
        scanf("%d",&size); } while(size!=1 && size!=2);
    switch(size){
        case 1: size=4; break;
        case 2: size=8; break;
        default :{
            printf("Automatically set to 4x4"); size=4; break;
        }
    }
    return size;
}


int menuC1(){
    int size;
    do{
        printf("-------------------- GENERATION --------------------\n"
               "Choose the size of the grid :\n\t1 - 4x4\n\t2 - 8x8\n");
        scanf("%d",&size); } while(size!=1 && size!=2);
    switch(size){
        case 1: size=4; break;
        case 2: size=8; break;
    }
    return size;
}
int menuC2(){
    int option;
    do{
        printf("What do you want to do ? \n\t1 - Show all lines possibilities\n\t2 - Generate automatically a grid (no still implemented)\n\t3- Return to menu\n");
        scanf("%d",&option);}
    while(option!=1 && option!=2 && option!=3);
    return option;
}

void show_grid(int** grid,int size){
    int i,j;
    char letter='A';
    printf("\n  ");
    for(j=0;j<size;j++) {
        printf("| %d ",j);
    }
    printf("|\n");
    for(i=0;i<size;i++){

        printf("%c |",letter);
        letter+=1;
        for(j=0;j<size;j++){
            if(grid[i][j]==-1) printf(" . |");
            else printf(" %d |",grid[i][j]);
        }
        printf("\n");
    }
}



