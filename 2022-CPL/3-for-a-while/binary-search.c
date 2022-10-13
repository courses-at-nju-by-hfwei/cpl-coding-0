// Created by hfwei on 2022/10/13.
//

#include <stdio.h>

//#define LEN INT_MAX
#define LEN 10
int dictionary[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

int main() {
  int key = 0;
  scanf("%d", &key);

  int index = -1;

  int low = 0;
  int high = LEN - 1;

  while (low <= high) {
    // int mid = low + (high - low) / 2
    int mid = (low + high) / 2;
    printf("low = %d \t high = %d\t mid = %d\n", low, high, mid);
//    printf("mid = %d\n", mid);

    if (key < dictionary[mid]) {
      high = mid - 1;
    } else if (key > dictionary[mid]) {
      low = mid + 1;
    } else {
      index = mid;
      break;
    }
  }

  if (index == -1) {
    printf("Not found!\n");
  } else {
    printf("The index of %d is %d.\n", key, index);
  }

  return 0;
}