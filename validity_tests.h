#ifndef TAKUZU_VALIDITY_TESTS_H
#define TAKUZU_VALIDITY_TESTS_H

typedef struct{
    int x;
    int y;
    int val;
} CASE;



int row_test(int** grid_game, int c, int size);
int column_test(int** grid_game, int c, int size);
int horizontal_seq_test(int** grid_game, int r, int c, int size);
int vertical_seq_test(int** grid_game, int r, int c, int size);
int validity_move(int** grid_game, CASE coord_case, int size);



#endif //TAKUZU_VALIDITY_TESTS_H
