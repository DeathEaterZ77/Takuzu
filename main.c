#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "manual_solving.h"
#include "solutions_grids.h"

int main() {
    int run = 1;
    while (run == 1) {
        int part = menu();
        switch (part) {
            case 1: {
                int size = menuA1();
                getchar();
                int option = menuA2();
                switch (option) {
                    case 1: {
                        int **manual_mask = enter_mask(size);
                        printf("Your entered mask :\n");
                        show_grid(manual_mask, size);
                        int **tab_solu = get_tab(size);
                        int **grid_game = apply_masktosolu(manual_mask, tab_solu, size);
                        show_grid(grid_game, size);
                        play(grid_game, tab_solu, size);
                        break;
                    }
                    case 2: {
                        int **auto_mask = generate_mask(size);
                        printf("Your generated mask :\n");
                        show_grid(auto_mask, size);
                        printf("test1");
                        int **tab_solu = get_tab(size);
                        printf("test1");
                        int **grid_game = apply_masktosolu(auto_mask, tab_solu, size);
                        printf("test1");

                        show_grid(grid_game, size);
                        play(grid_game, tab_solu, size);
                        break;
                    }
                    case 3: {
                        int **auto_mask = generate_mask(size);
                        int **tab_solu = get_tab(size);
                        int **grid_game = apply_masktosolu(auto_mask, tab_solu, size);
                        play(grid_game, tab_solu, size);
                        break;
                    }
                    case 4: {
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

            case 4: run = 0; break;

            default :
                printf("You have to choose between 1 and 3...");
                break;
        }

    }
}
