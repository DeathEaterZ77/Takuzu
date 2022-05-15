#ifndef TAKUZU_MANUAL_SOLVING_H
#define TAKUZU_MANUAL_SOLVING_H

int** init_matrix(int size);
int** enter_mask(int size);
int** generate_mask(int size);
int** apply_masktosolu(int** mask, int** solution, int size);

#include "validity_tests.h"
CASE get_case(int** grid_game, int size);
void play(int** grid_game, int size);

#endif //TAKUZU_MANUAL_SOLVING_H
