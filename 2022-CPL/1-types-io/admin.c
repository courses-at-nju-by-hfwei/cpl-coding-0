//
// Created by hengxin on 9/29/22.
//

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main() {
  /*
   * name and gender
   */
  char first_name[] = "Tayu";
  char last_name[] = "Lo";
  char gender = 'm';

  /*
   * birthday
   */
  int birth_year = 1954;
  int birth_month = 7;
  int birth_day = 20;
  char weekday[] = "Tuesday";

  /*
   * scores
   */
  int c_score = 40;
  int music_score = 99;
  int medicine_score = 80;

  /*
   * statistics
   */
  double mean = (c_score + music_score + medicine_score) / 3.0;
  double standard_deviation = sqrt(
      (pow(c_score - mean, 2)
      + pow(music_score - mean, 2)
      + pow(medicine_score - mean, 2)) / 3.0);
  int rank = 10;

  /*
   * Expected output
   * Tayu Lo 	 M
   * 07-20-1954, Tue.
   * C = 40 	 Music = 100 	 Medicine = 80
   * Mean = 73.3 	 SD = 24.94 	 Top = 10%
   */
  printf("%s %s \t %c\n"
         "%.2d-%d-%d, %.3s.\n"
         "C = %d \t Music = %d \t Medicine = %d\n"
         "Mean = %.1f \t SD = %.2f \t Top = %d%%\n",
         first_name, last_name, toupper(gender),
         birth_month, birth_day, birth_year, weekday,
         c_score, music_score, medicine_score,
         mean, standard_deviation, rank);
}