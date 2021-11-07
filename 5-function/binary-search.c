//
// Created by hengxin on 10/23/21.
//

#include <stdio.h>

#define LEN 10
int dictionary[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

/**
 * Binary search for the KEY in the array DICT of length LEN.
 *
 * @param dict The array in which key is to be searched.
 * @param len The length of the array.
 * @param key The key to search for.
 * @return The index of the key in the array; -1 if the key is not found.
 */
int BinarySearch(const int dict[], int len, int key);

int main() {
  int key = 0;
  scanf("%d", &key);

  int index = BinarySearch(dictionary, LEN, key);

  if (index == -1) {
    printf("Not found!\n");
  } else {
    printf("The index of %d is %d.\n", key, index);
  }

  return 0;
}

int BinarySearch(const int dict[], int len, int key) {
  int low = 0;
  int high = len - 1;
  int mid = 0;

  while (low <= high) {
    mid = (low + high) / 2;
    if (key < dict[mid]) {
      high = mid - 1;
    } else if (key > dict[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}