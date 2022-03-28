/**
 * file: strcpy.c
 *
 * Created by hengxin on 11/28/21.
 *
 * strcpy vs. strcpy_s (safe/secure; optional in C++)
 * strncpy vs. strncpy_s (optional in C11)
 * keyword "restrict"
 */

#include <string.h>
#include <stdio.h>

/**
 * Copy string at src to dest.
 * We assume that there is enough room in dest for storing src.
 *
 * @param dest
 * @param src
 */
void StrCpy(char *dest, const char *src);
void StrCpy1(char *dest, const char *src);
void StrCpy2(char *dest, const char *src);
void StrCpy3(char *dest, const char *src);
void StrCpy4(char *dest, const char *src);
char* StrCpyStd(char *dest, const char *src);

int main() {
  const char *src = "Hello World";
  char dest[strlen(src) + 1];

  StrCpy(dest, src);
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

  // the following code is unnecessary for this version
  //  dest[i] = '\0';
}

void StrCpy2(char *dest, const char *src) {
  int i = 0;
  while ((* (dest + i) = * (src + i)) != '\0') {
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

void StrCpy5(char *dest, const char *src) {
  while ((*dest++ = *src++));
}

// for exam
void f(char *dest, const char *src) {
  while ((*dest++ = *src++));
}

/**
 * @return The dest pointer
 */
char *StrCpyStd(char *dest, const char *src) {
  for (char *s = dest; (*s++ = *src++) != '\0'; );

  return dest;
}