//
// Created by hfwei on 2022/11/25.
//

#include <string.h>
#include <stdio.h>

/**
 * @brief Copy the string pointed to by src (including the terminating null character)
 *  into the array pointed to by dest.
 *  If copying takes place between objects that overlap,
 *  the behavior is undefined.
 *
 *  We assume that there is enough room in dest for storing src.
 *  Otherwise, it is an undefined behavior.
 *
 * @param dest
 * @param src
 */
void StrCpy(char *dest, const char *src);
void StrCpy1(char *dest, const char *src);
void StrCpy2(char *dest, const char *src);
void StrCpy3(char *dest, const char *src);
void StrCpy4(char *dest, const char *src);
void StrCpy5(char *dest, const char *src);
char *StrCpyStd(char *dest, const char *src);

int main() {
  const char *src = "Hello World";
  char dest[strlen(src) + 1];

  // StrCpy(dest, src);
  // printf("dest = %s\n", dest);

  strcpy_s(dest, sizeof dest / sizeof dest[0], src);
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
  int i = 0;
  while ((*(dest + i) = *(src + i)) != '\0') {
    i++;
  }
}

void StrCpy3(char *dest, const char *src) {
  while ((*dest = *src) != '\0') {
    src++;
    dest++;
  }
}

void StrCpy4(char *dest, const char *src) {
  while ((*dest++ = *src++) != '\0');
}

// NOT recommended!
void StrCpy5(char *dest, const char *src) {
  while ((*dest++ = *src++));
}

char *StrCpyStd(char *dest, const char *src) {
  for (char *s = dest; (*s++ = *src++) != '\0';);
  return dest;
}