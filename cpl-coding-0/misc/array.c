//
// Created by hfwei on 2022/10/25.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
  int array[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  printf("array[0][7] = %d\n", array[0][7]);

  int *ptrarray[42];
  for (int i = 0; i < 42; i++) {
    ptrarray[i] = malloc(100 * sizeof **ptrarray);
  }

  return 0;
}