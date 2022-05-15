#include "stdio.h"
#include "stdlib.h"
#include "validity_tests.h"



int row_test(int** grid_game, int r, int size){
    int zero=0, one=0;
    for(int c=0; c<size; c++){
        if (grid_game[r][c]==0) zero++;
        else if(grid_game[r][c]==1) one++;
    }
    if(zero==size/2) return 0;
    else if(one==size/2) return 1;
    return -1;
}

int column_test(int** grid_game, int c, int size){
    int zero=0, one=0;
    for(int r=0; r<size; r++){
        if (grid_game[r][c]==0) zero++;
        else if(grid_game[r][c]==1) one++;
    }
    if(zero==size/2) return 0;
    else if(one==size/2) return 1;
    return -1;
}

int horizontal_seq_test(int** grid_game, int r, int c, int size){
    if ((c > 1) && (grid_game[r][c-1]==grid_game[r][c-2]) && grid_game[r][c - 1] != -1) return grid_game[r][c-1];
    if ((c < size-2) && (grid_game[r][c+1]==grid_game[r][c+2])&& grid_game[c][r + 1] != -1) return grid_game[r][c+1];
    if ((c > 0) && (c<size-1) && (grid_game[r][c-1]==grid_game[r][c+1])) return grid_game[r][c-1];
    return -1;
}

int vertical_seq_test(int** grid_game, int r, int c, int size){
    if ((r > 1) && (grid_game[r-1][c]==grid_game[r-2][c]) && grid_game[r - 1][c] != -1) return grid_game[r-1][c];
    if ((r < size-2) && (grid_game[r+1][c]==grid_game[r+2][c]) && grid_game[r + 1][c] != -1) return grid_game[r+1][c];
    if ((r > 0) && (r<size-1) && (grid_game[r-1][c]==grid_game[r+1][c])) return grid_game[r-1][c];
    return -1;
}

int validity_move(int** grid_game, CASE coord_case, int size){
    int result;
    result = row_test(grid_game, coord_case.x, size);
    if ((result!=-1) && (result == coord_case.val)) return 1;

    result = column_test(grid_game, coord_case.y, size);
    if ((result!=-1) && (result == coord_case.val)) return 2;

    result = horizontal_seq_test(grid_game, coord_case.x, coord_case.y, size);
    if ((result!=-1) && (result == coord_case.val)) return 3;

    result = vertical_seq_test(grid_game, coord_case.x, coord_case.y, size);
    if ((result!=-1) && (result == coord_case.val)) return 4;

    return 0;
}
