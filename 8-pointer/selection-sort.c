/**
 * file: selection-sort.c
 *
 * Created by hengxin on 11/28/21.
 */

#include <stdio.h>
#include <stdlib.h>

//#define LEN 20
//int numbers[LEN] = {0};

void Swap(int *left, int *right);
void Print(const int arr[], int len);

/**
 * Sort the array ARR of length LEN using the selection sort algorithm.
 *
 * @param arr The array to be sorted.
 * @param len The length of the array.
 */
void SelectionSort(int *arr, int len);

int main() {
  /**
   * Input the array
   * Note: fails to run this program in "Run" (Ctrl + D)
   * See: https://youtrack.jetbrains.com/issue/CPP-5704
   * Use "Terminal" instead.
   */
//  int len = -1;
//  while (scanf("%d", &numbers[++len]) != EOF);

  int len = 0;
  printf("Please enter the length of the array to sort.\n");
  scanf("%d", &len);
  int *numbers = malloc(len * sizeof *numbers);

  printf("Please enter %d integers.\n", len);
  if (numbers == NULL) {
    printf("Error! Memory Not Allocated!\n");
    return 0;
  }

  for (int i = 0; i < len; i++) {
    scanf("%d", &numbers[i]);
  }

  SelectionSort(numbers, len);
  Print(numbers, len);

  free(numbers);

  return 0;
}

void Print(const int arr[], int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void SelectionSort(int *arr, int len) {
  for (int i = 0; i < len; ++i) {
    int min = arr[i];
//    int min = i[arr]; // DO NOT DO THIS UGLY TRICK!!!
    int min_index = i;

    for (int j = i + 1; j < len; j++) {
      if (min > arr[j]) {
        min = arr[j];
        min_index = j;
      }
    }

    Swap(&arr[i], &arr[min_index]);
  }
}

void Swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
}