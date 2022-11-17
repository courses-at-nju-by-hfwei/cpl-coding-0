// Created by hfwei on 2022/10/13.
//

#include <stdio.h>
#include <stdlib.h>

void WrongSwap(int left, int right);
void Swap(int *left, int *right);
void Print(const int *arr, int len);
void SelectionSort(int *arr, int len);

int main() {
  int len = 0;
  printf("Please input the length of the array to sort.\n");
  scanf("%d", &len);

  // void *: the type for a generic pointer (replacing char *)
  int *numbers = malloc(len * sizeof(*numbers));
  // null pointer: not the same with any non-null pointers
  // #define NULL ((void *) 0); but do not rely on it
  if (numbers == NULL) {
    printf("Error! Memory Not Allocated!\n");
    return 0;
  }

  for (int i = 0; i < len; i++) {
    scanf("%d", numbers + i);
  }

  Print(numbers, len);
  // numbers: the address of the first element of the `numbers` array
  // pass by value: the copy of the address of the first element of the `numbers` array
  SelectionSort(numbers, len);
  Print(numbers, len);

  // avoid memory leak (why memory leak?)
  free(numbers);
  // undefined behavior
  // free(numbers);
  // numbers[5] = 5;
}

void Print(const int *arr, int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// arr: the (copy of the) address of the first element of the `numbers` array
void SelectionSort(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    // find the minimum of numbers[i .. len - 1]
    // arr[i] is a syntactic sugar for *(arr + i)
    int min = *(arr + i);
    int min_index = i;
    for (int j = i + 1; j < len; j++) {
      if (*(arr + j) < min) {
        min = *(arr + j);
        min_index = j;
      }
    }

    // swap arr[i] and arr[min_index]
    // WrongSwap(arr[i], arr[min_index]);
    // &(*(arr + i))
    // Swap(&arr[i], &arr[min_index]);
    // &arr[i] is the same as (arr + i)
    Swap(arr + i, arr + min_index);
  }
}

void Swap(int *left, int *right) {
  int temp = *left;
  *left = *right;
  *right = temp;
}

// Wrong WrongSwap: does not work
void WrongSwap(int left, int right) {
  int tmp = left;
  left = right;
  right = tmp;
}