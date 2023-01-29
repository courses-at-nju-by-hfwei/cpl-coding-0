/**
 * file: echo-escaped.c
 *
 * Created by hengxin on 12/01/22.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// -e: escaped; -E: not escaped; must be in argv[1]
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: -e for escaped; -E for unescaped\n");
    return 0;
  }

  bool escaped = false;
  char *flag = argv[1];
  if (strcmp(flag, "-e") == 0) {
    escaped = true;
  } else if (strcmp(flag, "-E") != 0) {
    printf("Illegal flag '%s'\n"
           "Use -e or -E.\n", flag);
    return 0;
  }

  char **args = argv + 1;
  char *arg = NULL;
  while ((arg = *++args) != NULL) {
    if (strcmp(arg, "\\t") == 0 && escaped) {
      printf("\t");
    } else if (strcmp(arg, "\\n") == 0 && escaped) {
      printf("\n");
    } else {
      printf("%s ", arg);
    }
  }

  return 0;
}