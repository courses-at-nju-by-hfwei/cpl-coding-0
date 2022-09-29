//
// Created by hengxin on 9/29/22.
//

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main() {
  /*
   * Name and gender
   */
  char first_name[10];
  char last_name[10];
  char gender;

  /*
   * Birthday
   */
  int birth_year;
  int birth_month;
  int birth_day;
  char weekday[10];

  /*
   * Scores
   */
  int c_score;
  int music_score;
  int medicine_score;

  /*
   * Statistics
   */
  double mean;
  double standard_deviation;
  int rank;

  /*
   * Basic scanf:
   *
   * Tayu lo
   * M
   * 1957-7-20
   * Tuesday
   * 40 100 80
   * 73.3 24.94 10%
   */
//  scanf("%9s %9s %c %d-%d-%d %9s %d %d %d %lf %lf %d%%",
//        first_name, last_name, &gender,
//        &birth_year, &birth_month, &birth_day, weekday,
//        &c_score, &music_score, &medicine_score,
//        &mean, &standard_deviation,
//        &rank);

  /*
   * Expected scanf
   */
  scanf("%9s %9s %c %d-%d-%d %9s %d %d %d %*f %*f %d%%",
        first_name, last_name, &gender,
        &birth_year, &birth_month, &birth_day, weekday,
        &c_score, &music_score, &medicine_score,
        &rank);

  /**
   * Statistics
   */
  mean = (c_score + music_score + medicine_score) / 3.0;
  standard_deviation = sqrt((pow(c_score - mean, 2) + pow(music_score - mean, 2) + pow(medicine_score - mean, 2)) / 3.0);

  printf("%s %s \t %c \n"
         "%.2d-%d-%d, %.3s.\n"
         "C = %d \t Music = %d \t Medicine = %d\n"
         "Mean = %.1f \t SD = %.2f \t Top = %d%%\n",
         first_name, last_name, toupper(gender),
         birth_month, birth_day, birth_year, weekday,
         c_score, music_score, medicine_score,
         mean, standard_deviation, rank);

  return 0;
}