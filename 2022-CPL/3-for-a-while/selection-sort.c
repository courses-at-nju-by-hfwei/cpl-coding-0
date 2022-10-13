// Created by hfwei on 2022/10/13.
//

#include <stdio.h>

#define LEN 20
int numbers[LEN] = {0};

int main() {
  /*
   * Input the array
   * Note: fails to run this program in "Run" (Ctrl + D)
   * See: https://youtrack.jetbrains.com/issue/CPP-5704
   * Use "Terminal" instead.
   */
  int len = -1;
  while (scanf("%d", &numbers[++len]) != EOF);
//  while (scanf("%d", &numbers[++len]) == 1);

  for (int i = 0; i < len; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  printf("--------------------\n");
  for (int i = 0; i < len; i++) {
    // find the minimum of numbers[i .. len - 1]
    int min = numbers[i];
    int min_index = i;
    for (int j = i + 1; j < len; j++) {
      if (numbers[j] < min) {
        min = numbers[j];
        min_index = j;
      }
    }

    // swap numbers[i] and numbers[min_index]
    int tmp = numbers[i];
    numbers[i] = numbers[min_index];
    numbers[min_index] = tmp;

    // print it out
    for (int i = 0; i < len; i++) {
      printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("--------------------\n");
  }
}