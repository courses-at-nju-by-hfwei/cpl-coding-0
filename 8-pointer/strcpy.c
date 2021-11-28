/**
 * file: strcpy.c
 *
 * Created by hengxin on 11/28/21.
 */

#include <string.h>
#include <stdio.h>

void StrCpy(char *dest, const char *src);
void StrCpy1(char *dest, const char *src);
void StrCpy2(char *dest, const char *src);
void StrCpy3(char *dest, const char *src);
void StrCpy4(char *dest, const char *src);
char* StrCpyStd(char *dest, const char *src);

int main() {
  const char *src = "Hello World";
  char dest[strlen(src) + 1];

  StrCpy2(dest, src);
  printf("dest = %s\n", dest);

  return 0;
}

void StrCpy(char *dest, const char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }

  dest[i] = '\0';
}

void StrCpy1(char *dest, const char *src) {
  int i = 0;
  while ((dest[i] = src[i]) != '\0') {
    i++;
  }
}

void StrCpy2(char *dest, const char *src) {
  while ((*dest = *src) != '\0') {
    src++;
    dest++;
  }
}

void StrCpy3(char *dest, const char *src) {
  while ((*dest++ = *src++) != '\0');
}

void StrCpy4(char *dest, const char *src) {
  while ((*dest++ = *src++));
}

char *StrCpyStd(char *dest, const char *src) {
  for (char *s = dest; (*s++ = *src++) != '\0'; );

  return dest;
}