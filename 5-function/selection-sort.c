//
// Created by hengxin on 10/16/21.
//

#include <stdio.h>

#define MAX 20
int numbers[MAX] = {0};

void Swap(int left, int right);
void Print(const int arr[], int len);

/**
 * Sort the array ARR of length LEN using the selection sort algorithm.
 *
 * @param arr The array to be sorted.
 * @param len The length of the array.
 */
void SelectionSort(int arr[], int len);

int main() {
  /**
   * Input the array
   * Note: fails to run this program in "Run" (Ctrl + D)
   * See: https://youtrack.jetbrains.com/issue/CPP-5704
   * Use "Terminal" instead.
   */
  int len = -1;
  while (scanf("%d", &numbers[++len]) != EOF);

  SelectionSort(numbers, len);
  Print(numbers, len);

  return 0;
}

void Print(const int arr[], int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void SelectionSort(int arr[], int len) {
  for (int i = 0; i < len; ++i) {
    int min = arr[i];
    int min_index = i;

    for (int j = i + 1; j < len; j++) {
      if (min > arr[j]) {
        min = arr[j];
        min_index = j;
      }
    }

    /**
     * swap numbers[i] and numbers[min_index]
     */
    int tmp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = tmp;
//    Swap(arr[i], arr[min_index]);
  }
}

/**
 * Warning: This swap function does not work!!!
 * You will know why when you learn pointers in C.
 * Be patient.
 */
void Swap(int left, int right) {
  int tmp = left;
  left = right;
  right = tmp;
}