// Created by hfwei on 2022/10/13.
//

#include <stdio.h>
#include <string.h>

#define LEN 21
char string[LEN] = "";

int main() {
  scanf("%20s", string);

//  int len = 0;
//  while (string[len] != '\0') {
//    len++;
//  }
  int len = strlen(string);
  printf("The length of \"%s\" is %d.\n", string, len);

  int is_palindrome = 1;
  for (int i = 0, j = len - 1; i < j; i++, j--) {
    if (string[i] != string[j]) {
      is_palindrome = 0;
      break;
    }
  }

  printf("\"%s\" is %s a palindrome.\n", string,
         is_palindrome ? "" : "not");

  return 0;
}