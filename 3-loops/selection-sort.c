//
// Created by hengxin on 10/16/21.
//

#include <stdio.h>
#define LEN 5
int numbers[LEN] = {0};

int main() {
  /**
   * Input the array
   */
  for (int i = 0; i < LEN; i++) {
    scanf("%d", &numbers[i]);
  }

  /**
   * Print it out
   */
  for (int i = 0; i < LEN; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  printf("--------------------\n");
  for (int i = 0; i < LEN; ++i) {
    int min = numbers[i];
    int min_index = i;

    for (int j = i + 1; j < LEN; j++) {
      if (min > numbers[j]) {
        min = numbers[j];
        min_index = j;
      }
    }

    printf("min = %d \t min_index = %d\n", min, min_index);

    /**
     * swap numbers[i] and numbers[min_index]
     */
    int tmp = numbers[i];
    numbers[i] = numbers[min_index];
    numbers[min_index] = tmp;

    /**
     * Print it out again
     */
    for (int i = 0; i < LEN; i++) {
      printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("--------------------\n");
  }

  return 0;
}