// Created by hfwei on 2022/10/13.
//

#include <stdio.h>

#define LEN 20

void SelectionSort(int arr[], int len);
void Print(const int arr[], int len);
void Swap(int left, int right);

int main() {
  int numbers[LEN] = {0};

  /*
   * Input the array
   * Note: fails to run this program in "Run" (Ctrl + D)
   * See: https://youtrack.jetbrains.com/issue/CPP-5704
   * Use "Terminal" instead.
   */
  int len = -1;
  while (scanf("%d", &numbers[++len]) != EOF);

  Print(numbers, len);
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
  for (int i = 0; i < len; i++) {
    // find the minimum of numbers[i .. len - 1]
    int min = arr[i];
    int min_index = i;
    for (int j = i + 1; j < len; j++) {
      if (arr[j] < min) {
        min = arr[j];
        min_index = j;
      }
    }

    // swap arr[i] and arr[min_index]
    int tmp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = tmp;
//    Swap(arr[i], arr[min_index]);
  }
}

// Warning: This Swap function does not work!!!
// You will know why when you learn pointers in C.
// Be patient.
void Swap(int left, int right) {
  int temp = left;
  left = right;
  right = temp;
}