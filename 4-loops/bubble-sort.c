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
  /**
   * double "for" version
   */
//  int swapped;
//  for (int i = 0; i < LEN; i++) {
//    swapped = 0;
//    for (int j = 0; j < LEN - 1 - i; j++) {
//      if (numbers[j] > numbers[j + 1]) {
//        int tmp = numbers[j];
//        numbers[j] = numbers[j + 1];
//        numbers[j + 1] = tmp;
//        swapped = 1;
//      }
//    }
//    if (! swapped) {
//      break;
//    }
//  }

  /**
   * The optimized version runs slower!!!
   */
  int swapped;
  int len = LEN;
  int new_len;
  do {
    swapped = 0;
    new_len = 0;
    for (int j = 0; j < len - 1; j++) {
      if (numbers[j] > numbers[j + 1]) {
        int tmp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = tmp;
        swapped = 1;
        new_len = j + 1;
      }
    }
//    len--;
    len = new_len;
  } while (swapped);

  /**
   * toupper
   * see https://stackoverflow.com/a/459704
   */
  clock_t diff = clock() - start;
  long sec = diff / CLOCKS_PER_SEC;
  printf("Sorting time taken %d seconds.\n", sec);

  for (int i = 0; i < LEN; i++) {
    printf("%d ", numbers[i]);
  }

  return 0;
}
