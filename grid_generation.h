#ifndef TAKUZU_GRID_GENERATION_H
#define TAKUZU_GRID_GENERATION_H
void show_valid_row();
int** valid_row(int size, int *count);
int *int_to_bin(int integer, int size);
int is_row_valid(int *binary, int size);
#endif //TAKUZU_GRID_GENERATION_H
