/**
 * file: scores.c
 *
 * Created by hengxin on 12/01/22.
 */

#include <stdio.h>
#include <stdlib.h>

#define COLS 3

void Print(int table[][COLS], int rows);

int main() {
  /**
   * C, Java, Python
   *
   * musician_score_table is a 2D (two-dimensional) array.
   * musician_score_table is an array of 5 arrays,
   * each of which contains 3 elements.
   */
  int rows = 0;
  printf("Please input the number of students.\n");
  scanf("%d", &rows);

  int (*musician_score_table)[COLS] = malloc(rows * COLS * sizeof *musician_score_table);
  if (musician_score_table == NULL) {
    printf("Failed to allocate memory.\n");
    return 0;
  }

  printf("Please input the scores of these students.\n");
  // for (int i = 0; i < rows * COLS; i++) {
  //   scanf("%d", &musician_score_table[i]);
  // }

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < COLS; col++) {
      scanf("%d", &musician_score_table[row][col]);
    }
  }

  Print(musician_score_table, rows);

  printf("musician_score_table[3][2] = %d\n",
         musician_score_table[3][2]);
  printf("musician_score_table[3][2] = %d\n",
         *(musician_score_table[3] + 2));
  printf("musician_score_table[3][2] = %d\n",
         (*(musician_score_table + 3))[2]);
  printf("musician_score_table[3][2] = %d\n",
         *(*(musician_score_table + 3) + 2));

  /**
   * musician_score_table is a pointer to (an array of 3 ints)
   */
  int (*ptr_scores)[COLS] = musician_score_table;
  printf("ptr_scores[3][2] = %d\n",
         (*(ptr_scores + 3))[2]);

  free(musician_score_table);

  return 0;
}

// int table[] : int *table
// int table[][cols] : int (*table)[cols]
void Print(int (*table)[COLS], int rows) {
  printf("\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }
}

// int student_score_table[ROWS][COLS] = {
//     {0, 10, 20},
//     {10, 20, 30},
//     {20, 30, 40},
//     {30, 40, 50},
//     {40, 50, 60}
// };