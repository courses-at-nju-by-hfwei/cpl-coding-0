// Created by hfwei on 2022/11/25.

#include <stdio.h>
#include <string.h>

#define LEN 10

void Swap(char **left, char **right);
void PrintStrs(const char *str[], int len);
void SelectionSort(char *str[], int len);

int main() {
  const char *musicians[LEN] = {
      "Luo Dayou",
      "Cui Jian",
      "Dou Wei",
      "Zhang Chu",
      "Li Zhi",
      "Wan Qing",
      "WuTiaoRen",
      "ZuoXiao",
      "Hu Mage",
      "He Yong",
  };

  PrintStrs(musicians, LEN);
  SelectionSort(musicians, LEN);
  PrintStrs(musicians, LEN);
}

void PrintStrs(const char *str[], int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%s\n", str[i]);
  }
  printf("\n");
}

void SelectionSort(char *str[], int len) {
  for (int i = 0; i < len; i++) {
    // find the minimum of musicians[i .. len - 1]
    const char *min = str[i];
    int min_index = i;

    for (int j = i + 1; j < len; j++) {
      if (strcmp(min, str[j]) > 0) {
        min = str[j];
        min_index = j;
      }
    }

    // swap str[i] and str[min_index]
    Swap(str + i, str + min_index);
  }
}

void Swap(char **left, char **right) {
  char *temp = *left;
  *left = *right;
  *right = temp;
}