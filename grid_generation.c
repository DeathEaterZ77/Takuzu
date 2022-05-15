#include "grid_generation.h"
#include "stdlib.h"
#include "math.h"
#include "stdio.h"


void show_valid_row(int size){
    printf("Valid rows  :\n");
    int count, i;
    int **valid_rows = valid_row(size, &count);
    for (i = 0; i < count; i++) {
        printf("\n\t- ");
        for (int j = 0; j < size; j++) {
            printf("%d ", valid_rows[i][j]);
        }
    }
    printf("\n");
}


int *int_to_bin(int integer, int size) {
    int *binary = (int *) malloc(sizeof(int) * size);
    int i;
    for (i = 0; i <= size - 1; i++) {
        if ((int) pow(2, size - 1 - i) <= integer) {
            binary[i] = 1;
            integer -= (int) pow(2, size - 1 - i);
        } else binary[i] = 0;
    }
    return binary;
}


int** valid_row(int size, int *count){
    int **binary = (int **) malloc(sizeof(int *) * (int) pow(2, size));
    int i, j = 0, valid = -1;
    for (i = 0; i < (int) pow(2, size); i++) {
        binary[j] = (int *) malloc(sizeof(int) * size);
        binary[j] = int_to_bin(i, size);

        if (is_row_valid(binary[j],size) == 1) j++;
    }
    *count = j;
    return binary;
}


int is_row_valid(int *binary, int size) {
    int count = 0, i;
    for (i = 0; i < size; i++) {
        if (binary[i] == 0) {
            count++;
        }
        if ((i < size - 3) && (binary[i] == binary[i + 1] && binary[i] == binary[i + 2]))
            return 0;
        if ((i > size - 3) && (binary[i] == binary[i - 1] && binary[i] == binary[i - 2]))
            return 0;
    }
    if (count == size / 2) return 1;
    else return 0;
}



