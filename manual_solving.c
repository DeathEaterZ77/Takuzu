#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "manual_solving.h"
#include "validity_tests.h"
#include "interface.h"

 int** enter_mask(int size){

     int** mask = malloc(sizeof(int*)*size);
     for(int i=0;i<size;i++){
         mask[i] = malloc(sizeof(int)*size);
         for(int j=0;j<size;j++){
             //char i_bis = (char)(i)+65;
             do {
                 printf("Enter the mask's value of the case %d%d : ", i, j);
                 scanf("%d", &mask[i][j]);
             } while((mask[i][j]!=0) && (mask[i][j]!=1));
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
                if ((rand() % size == 1) && (mask[i][j]!=1) && (nb_cases != 0)) {
                    mask[i][j] = 1;
                    nb_cases--;
                }
            }
        }
    }
    return mask;
}

int** apply_masktosolu(int** mask, int** solu, int size){
    int** grid_game = init_matrix(size);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if (mask[i][j]==1){ grid_game[i][j] = solu[i][j]; }
            else { grid_game[i][j] = -1;}
        }
    }
    return grid_game;
}

CASE get_case(int** grid_game, int size){
    CASE your_case;
    do{
        char x; int y;
        printf("Choose the case : ");
        scanf(" %c%d",&x,&y);
        your_case.x = (int)(x)-65;
        your_case.y = y;
    } while( grid_game[your_case.x][your_case.y] != -1);
    do{
        int value;
        printf("Enter this case's value 0 or 1 : ");
        scanf(" %d",&value);
        your_case.val = value;
    } while( your_case.val !=0 && your_case.val !=1);

    return your_case;
}

int verify_solution(int** grid_game, int** grid_solu, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if ( grid_game[i][j] != grid_solu[i][j] ) return 0;
        }
    }
    return 1;
}

void play(int** grid_game, int** grid_solu, int size){

    int life=3, win_game=0, verif;
    CASE coord_case;
    while(life!=0 && win_game==0){

        show_grid(grid_game, size);
        printf("\n==> %d lives left <==\n",life);
        coord_case = get_case(grid_game, size);
        verif = validity_move(grid_game, coord_case, size);
        if (verif==0){
            if( coord_case.val == grid_solu[coord_case.x][coord_case.y] ){
                grid_game[coord_case.x][coord_case.y] = coord_case.val;
                printf("\nCorrect move !");
                win_game = verify_solution(grid_game, grid_solu, size);
            }
            else{
                printf("\nValid move but incorrect !");
            }
        }
        else{
            life--;
            printf("\nInvalid move ! You lose one life, so you got %d left...\n", life);
            switch(verif){
                case 1: printf("There is already half the %d's row filled with %d !", coord_case.x, coord_case.val); break;
                case 2: printf("There is already half the %d's column filled with %d !", coord_case.y, coord_case.val); break;
                case 3: printf("You can't have a sequence of the 3 same values on the %d's row !", coord_case.x); break;
                case 4: printf("You can't have a sequence of the 3 same values on the %d's column !", coord_case.x); break;
            }
        }
        printf("\n");
    }
    if (life != 0){
        printf("Congrats ! You won the game !");
        show_grid(grid_game, size);
    }
    else{
        printf("You lost all your lives...\nGAME OVER\n\nThe solution was :\n");
        show_grid(grid_solu, size);
    }

}

