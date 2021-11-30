/**
 * file: strcmp.c
 *
 * Created by hengxin on 11/28/21.
 */

#include <stdio.h>

int StrCmp(const char *s1, const char *s2);
int StrCmpStd(const char *s1, const char *s2);

int main() {
  const char *str1 = "hi, hengxin";
  const char *str2 = "hi, ant";

  printf("%s %c %s\n",
         str1, StrCmp(str1, str2) > 0 ? '>' : '<', str2);

  return 0;
}

int StrCmp(const char *s1, const char *s2) {
  while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
    s1++;
    s2++;
  }

  if (*s1 == '\0' && *s2 == '\0') {
    return 0;
  }

  return *s1 - *s2;
}

int StrCmpStd(const char *s1, const char *s2) {
  for ( ; *s1 == *s2; s1++, s2++) {
    if (*s1 == '\0') {
      return 0;
    }
  }

  return ((* (unsigned char *) s1)
    < ((* (unsigned char *) s2))) ? -1 : 1;
}
