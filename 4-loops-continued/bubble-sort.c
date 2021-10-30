/**
 * Bubble Sort Algorithm
 * See https://en.wikipedia.org/wiki/Bubble_sort
 *
 * Created by hengxin on 10/30/21.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LEN 100000
//int numbers[LEN] = {6, 5, 3, 1, 8, 7, 2, 4};
int numbers[LEN] = { 0 };

int main() {
  srand(time(NULL));
  for (int i = 0; i < LEN; i++) {
    numbers[i] = rand() % LEN;
  }

  clock_t start = clock();
  int swap;
  for (int i = 0; i < LEN; i++) {
    swap = 0;
    for (int j = 0; j < LEN - 1 - i; j++) {
      if (numbers[j] > numbers[j + 1]) {
        int tmp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = tmp;
        swap = 1;
      }
    }
    if (! swap) {
      break;
    }
  }

  /**
   * timing
   * see https://stackoverflow.com/a/459704
   */
  clock_t diff = clock() - start;
  int msec = diff * 1000 / CLOCKS_PER_SEC;
  printf("Sorting time taken %d seconds %d milliseconds.\n", msec/1000, msec%1000);

  for (int i = 0; i < LEN; i++) {
    printf("%d ", numbers[i]);
  }

  return 0;
}
