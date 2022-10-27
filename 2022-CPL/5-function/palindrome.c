// Created by hfwei on 2022/10/13.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN 21
char string[LEN] = "";

int StrLen(const char str[]);
bool IsPalindrome(const char str[], int len);

int main() {
  // example: nolemon,nomelon
  scanf("%20s", string);

  int len = StrLen(string);
//  int len = strlen(string);
  printf("The length of \"%s\" is %d.\n", string, len);

  printf("\"%s\" is%s a palindrome.\n", string,
         IsPalindrome(string, len) ? "" : " not");

  return 0;
}

int StrLen(const char str[]) {
  int len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

bool IsPalindrome(const char str[], int len) {
  for (int i = 0, j = len - 1; i < j; i++, j--) {
    if (str[i] != str[j]) {
      return false;
    }
  }

  return true;
}