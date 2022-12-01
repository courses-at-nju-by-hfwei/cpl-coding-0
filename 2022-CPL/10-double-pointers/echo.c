/**
 * file: echo.c
 *
 * Echo program (command-line) arguments.
 *
 * Created by hengxin on 12/01/22.
 */

#include <stdio.h>

/**
 * @param argc argument count.
 * @param argv argument vector.
 *   By convention (not the C standard), argv[0] is the name by which the program was invoked.
 *   By the C standard, argv[argc] is a null pointer.
 *   argv[1] .. argv[argc - 1] are the command-line parameters.
 */

// int argv[] : int *arg
// char *argv[] : char **argv
int main(int argc, char **argv) {
  printf("argc = %d, program = %s\n", argc, argv[0]);

  // (1) char *argv[]
  // for (int i = 1; i < argc; i++) {
  //   printf("%s\n", argv[i]);
  // }

  // (2) char **argv (for version)
  // for (char **ptr = argv + 1; *ptr != NULL; ptr++) {
  //   printf("%s ", *ptr);
  // }

  // (3) char **argv (while version)
  // char **ptr = argv + 1;
  // while (*ptr != NULL) {
  //   printf("%s ", *ptr++);
  // }

  // (4) char **argv (while version with *++)
  // wrong version!!!
  // char **ptr = argv + 1;
  // while (*ptr++ != NULL) {
  //   printf("%s ", *ptr);
  // }

  // correct version ^^
  char **ptr = argv;
  char *arg = NULL;
  while ((arg = *++ptr) != NULL) {
    printf("%s ", arg);
  }

  return 0;
}