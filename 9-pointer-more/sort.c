/**
 * file: sort.c
 *
 * Created by hengxin on 12/5/21.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define LEN 10

int CompareInts(const void *left, const void *right);
void PrintInts(int integers[], int len);

int CompareStrs(const void *left, const void *right);
void PrintStrs(const char *str[], int len);

int main() {
  /**
   * Sorting an array of integers
   */
  int integers[] = { -2, 99, 0, -743, 2, INT_MIN, 4 };
  int size_of_integers = sizeof integers / sizeof *integers;

  /**
   * void qsort( void *ptr, size_t count, size_t size,
            int (*comp)(const void *, const void *) );
   */
  qsort(integers, size_of_integers, sizeof *integers, CompareInts);
  PrintInts(integers, size_of_integers);

  /**
   * Sorting an array of strings
   */
  const char *names[LEN] = {
      "Luo Dayou",
      "Cui Jian",
      "Dou Wei",
      "Zhang Chu",
      "He Yong",
      "Wan Qing",
      "WuTiaoRen",
      "ZuoXiao",
      "Hu Mage",
      "Li Zhi"
  };
  int size_of_names = sizeof names / sizeof *names;

  qsort(names, size_of_names, sizeof *names, CompareStrs);
  PrintStrs(names, LEN);
}

int CompareInts(const void *left, const void *right) {
  int int_left = * (const int*) left;
  int int_right = * (const int*) right;

  if (int_left < int_right) {
    return -1;
  }

  if (int_left > int_right) {
    return 1;
  }

  // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)

  return 0;
}

int CompareStrs(const void *left, const void *right) {
  char *const *pp1 = left;
  char *const *pp2 = right;
  return strcmp(*pp1, *pp2);
}

void PrintInts(int integers[], int len) {
  printf("\n");
  for (int i = 0; i < len; ++i) {
    printf("%d ", integers[i]);
  }
  printf("\n");
}

void PrintStrs(const char *str[], int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%s\n", str[i]);
  }
  printf("\n");
}
