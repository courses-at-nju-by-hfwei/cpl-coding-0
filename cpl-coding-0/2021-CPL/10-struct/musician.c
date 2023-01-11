/**
 * file: musician.c
 *
 * Created by hengxin on 12/12/21.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum gender {
  MALE, FEMALE
} Gender;

typedef struct score {
  int c_score;
  int java_score;
  int python_score;
} Score;

typedef struct musician {
  char *name;
//  enum {MALE, FEMALE} gender;
  Gender gender;

  char *album;

  Score score;
} Musician;

void PrintMusician(const Musician *m);
Musician MakeMusician(char *name, Gender gender,
                      char *album,
                      int c_score, int java_score, int python_score);
int TotalScore(const Musician *m);
int CompareMusicians(const void *m1, const void *m2);

int main() {
  Musician luo = {
      "Luo Dayou", MALE,
      "之乎者也",
      20, 30, 40
  };

  Musician cui = {
      .name = "Cui Jian",
      .gender = MALE,
      .album = "新长征路上的摇滚",
      .score = {
          .c_score = 10,
          .java_score = 20,
          .python_score = 30
      }
  };

  Musician zhang = {
      .name = "Zhang Chu",
      .gender = MALE,
//      .album = "一颗不肯媚俗的心",
      .score = {
        .c_score = 0,
        .java_score = 10,
        .python_score = 20
      }
  };
  zhang.album = malloc(50 * sizeof *zhang.album);
  strcpy(zhang.album, "一颗不肯媚俗的心");

  Musician musicians[] = {luo, cui, zhang};
  int len = sizeof musicians / sizeof *musicians;
  for (int i = 0; i < len; i++) {
    PrintMusician(musicians + i);
  }

  qsort(musicians, len, sizeof(*musicians), CompareMusicians);
  for (int i = 0; i < len; i++) {
    PrintMusician(musicians + i);
  }

  Musician li = zhang;
  li.name = "Li Chaochao";
  // It is even possible for an enum variable
  // to hold an integer that does not represent any of the enumeration values.
  li.gender = 'M';
  // Danger! Now li.album and zhang.album point to the same album.
  strcpy(li.album, "两颗不肯媚俗的心");

  PrintMusician(&li);
  PrintMusician(&zhang);

  free(zhang.album);
}

void PrintMusician(const Musician *m) {
  printf("\n");
  printf("%s\n%c\n%s\n%d\t%d\t%d\n",
         m->name,
         m->gender == MALE ? 'M' : 'F',
         m->album,
         m->score.c_score, m->score.java_score, m->score.python_score);
  printf("\n");
}

int CompareMusicians(const void *m1, const void *m2) {
  int score_1 = TotalScore(m1);
  int score_2 = TotalScore(m2);

  if (score_1 > score_2) {
    return 1;
  }

  if (score_1 < score_2) {
    return -1;
  }

  return 0;
}

int TotalScore(const Musician *m) {
  return m->score.c_score + m->score.java_score + m->score.python_score;
}

Musician MakeMusician(char *name, Gender gender,
                      char *album,
                      int c_score, int java_score, int python_score) {
  Musician m;
  m.name = malloc(strlen(name) + 1);
  strcpy(m.name, name);

  m.gender = gender;

  m.album = malloc(strlen(album) + 1);
  strcpy(m.album, album);

  m.score.c_score = c_score;
  m.score.java_score = java_score;
  m.score.python_score = python_score;

  return m;
}