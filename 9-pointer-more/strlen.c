/**
 * file: strlen.c
 *
 * Created by hengxin on 11/28/21.
 */

#include <stdio.h>

int StrLen(const char *s);
size_t StrLenStd(const char *s);

int main() {
  /**
   * a copy of "Hello World!" in the data segment
   */
  char msg[20] = "Hello World!";
  msg[0] = 'N';

  /**
   * This string literal "Hello World!" is stored in the text segment
   */
  char *ptr_msg = "Hello World!";
//  *ptr_msg = 'N';

  printf("The length of the message \"%s\" = %d\n",
         msg, StrLen(msg));

  return 0;
}

int StrLen(const char *s) {
  int len = 0;
  while (s[len] != '\0') {
    len++;
  }

  return len;
}

size_t StrLenStd(const char *s) {
  const char *sc;
  for (sc = s; *sc != '\0'; sc++);

  return (sc - s);
}

// for exam
size_t f(const char *s) {
  const char *sc;
  for (sc = s; *sc != '\0'; sc++);

  return (sc - s);
}
