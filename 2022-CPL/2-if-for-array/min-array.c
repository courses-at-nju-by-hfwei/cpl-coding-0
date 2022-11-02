// Created by hfwei on 2022/10/6.
//

#include <stdio.h>

#define NUM 5

int main() {
  int numbers[NUM] = {23, 56, 19, 11, 78};

  int min = numbers[0];

  // iteration 0: i = 1, i < 5 holds, min = 23, i = 2
  // iteration 1: i = 2, i < 5 holds, min = 19, i = 3
  // iteration 2: i = 3, i < 5 holds, min = 11, i = 4
  // iteration 3: i = 4, i < 5 holds, min = 11, i = 5
  // iteration 4: i = 5, i < 5 fails, terminates
  for (int i = 1; i < NUM; ++i) { // iterate over the elements of an array
    if (numbers[i] < min) { // repeat doing something on each element
      min = numbers[i];
    }
  }

  printf("min = %d\n", min);

  return 0;
}