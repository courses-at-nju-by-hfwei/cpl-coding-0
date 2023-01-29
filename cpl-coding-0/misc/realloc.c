//
// Created by hfwei on 2023/1/29.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
  char *b = malloc(5);
  int st = 0;

  while (1) {
    memcpy(b + st * 5, "hello", 5);
    b = realloc(b, 10 + st * 5);
    st++;
    printf("%d\n", st);
  }

  return 0;
}