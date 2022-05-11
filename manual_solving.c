#include "stdlib.h"
#include "stdio.h"
#include "manual_solving.h"

 int** enter_mask(int size){

     int** mask = malloc(sizeof(int*)*size);
     for(int i=0;i<size;i++){
         mask[i] = malloc(sizeof(int)*size);
         for(int j=0;j<size;j++){
             //char i_bis = (char)(i)+65;
             do {
                 printf("Enter the mask's value of the case %d%d : ", i, j);
                 scanf("%d", &mask[i][j]);
             } while(mask[i][j]!=0 && mask[i][j]!=1);
         }
     }
     return mask;
}