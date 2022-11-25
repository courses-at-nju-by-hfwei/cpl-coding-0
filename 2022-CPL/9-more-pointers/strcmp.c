//
// Created by hfwei on 2022/11/25.
//

#include <stdio.h>

/**
 * @brief Compares the string pointed to by s1 to the string pointed to by s2
 * @param s1 the first string
 * @param s2 the second string
 * @return > 0 if s1 > s2; 0 if s1 = s2; < 0 if s1 < s2.
 */
int StrCmp(const char *s1, const char *s2);
int StrCmpStd(const char *s1, const char *s2);

/**
 * @brief Compare no more than n characters
 *        (characters that follow '\0' are not compared)
 *        from the array pointed to by s1 to the array pointed to by s2.
 * @param s1
 * @param s2
 * @param n
 * @return
 */
int StrNCmp(const char *s1, const char *s2, int n);
int StrNCmpStd(const char *s1, const char *s2, int n);

int main() {
  const char *str1 = "hi, C";
  const char *str2 = "hi, c";

  printf("StrCmp(\"%s\", \"%s\") = %d\n",
         str1, str2, StrCmp(str1, str2));
  printf("StrCmpStd(\"%s\", \"%s\") = %d\n",
         str1, str2, StrCmpStd(str1, str2));

  int n = 2;
  printf("StrNCmp(\"%s\", \"%s\", %d) = %d\n",
         str1, str2, n, StrNCmp(str1, str2, n));

  return 0;
}

int StrCmp(const char *s1, const char *s2) {
  while (*s1 == *s2 && (*s1 != '\0' && *s2 != '\0')) {
    s1++;
    s2++;
  }

  // four cases here
  if (*s1 == '\0' && *s2 == '\0') {
    return 0;
  }

  return (*(const unsigned char *) s1)
             < (*(const unsigned char *) s2) ? -1 : 1;
}

int StrCmpStd(const char *s1, const char *s2) {
  for (; *s1 == *s2; s1++, s2++) {
    if (*s1 == '\0') {
      return 0;
    }
  }

  return (*(const unsigned char *) s1)
             < (*(const unsigned char *) s2) ? -1 : 1;
}

int StrNCmp(const char *s1, const char *s2, int n) {
  for (int i = 0; i < n; i++) {
    if (*s1 != *s2) {
      return (*(const unsigned char *) s1)
                 < (*(const unsigned char *) s2) ? -1 : 1;
    } else {  // *s1 = *s2
      if (*s1 == '\0') {
        return 0;
      } else {
        s1++;
        s2++;
      }
    }
  }

  return 0;
}

int StrNCmpStd(const char *s1, const char *s2, int n) {
  for (; 0 < n; n--, s1++, s2++) {
    if (*s1 != *s2) {
      return (*(const unsigned char *) s1)
                 < (*(const unsigned char *) s2) ? -1 : 1;
    } else if (*s1 == '\0') {
      return 0;
    }
  }

  return 0;
}