//
// Created by hfwei on 2022/11/25.
//

#include <stdio.h>

int StrLen(const char *str);
size_t StrLenStd(const char *str);

int main() {
  char msg[20] = "Hello World!";
  msg[0] = 'N';
  printf("%s\n", msg);

  // create an anonymous array of `char`
  // that may be stored in read-only memory
  char *ptr_msg = "Hello World!";
  // undefined behavior
  // interpreted by signal 11: SIGSEGV
  // SIG: Signal; SEGV: segmentation violation
  *ptr_msg = 'N';
  // ptr_msg[0] = 'N';
  printf("%s\n", msg);

  printf("StrLen(%s) = %d\n", msg, StrLen(msg));
  printf("StrLenStd(%s) = %d\n", msg, StrLen(msg));

  return 0;
}

int StrLen(const char *str) {
  int len = 0;
  while (str[len] != '\0') {
    len++;
  }
  // printf("%d", '\0');

  return len;
}

size_t StrLenStd(const char *str) {
  const char *sc;
  for (sc = str; *sc != '\0'; sc++);

  return (sc - str);
}