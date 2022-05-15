#include "auto_solving.h"
#include "interface.h"
#include "validity_tests.h"
#include "stdio.h"
#include "stdlib.h"

void auto_solve(int **game_grid, int **solu_grid,int size){
    show_grid(game_grid,size);
    int i=0, j=0, valid;
    while (i < size) {
        while (j < size) {

            if (game_grid[i][j] == -1) {
                valid = is_case_valid(i, j, game_grid, size);
                if (valid != -1) {
                    game_grid[i][j] = valid;
                    show_grid(game_grid, size);
                    j = 0, i = 0;
                } else j++;
            } else j++;

        }

        int k, z;
        int full = 1;
        for (k = 0; k < size; k++) {
            for (z = 0; z < size; z++) {
                if (game_grid[k][z] == -1){
                    full = 0, z=size, k=size;
                }
            }
        }

        if (j == size && i == size - 1 && (full == 0)) {
            for (int x = 0; x < size; x++) {
                for (int y = 0; y < size; y++) {
                    if (game_grid[y][x] == -1) {
                        game_grid[y][x] = solu_grid[y][x];
                        x=size,y=size;

                    }
                }
            }
            show_grid(game_grid, size);
            i = 0, j = 0;
        } else {
            i++;
            j = 0;
        }
    }
    printf("\nSolved grid ! \n");
}

void add_case_from_solu(int **game_grid, int **solu_grid, int size){

}