//
// Created by hfwei on 2022/9/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int high = 100;
  int number_of_tries = 2;

  /**
   * (1) print the rules of the game to players
   */
  printf("==========\n"
         "Let us play the Guess the Number game.\n"
         "The computer will generate a random number between 1 and %d.\n"
         "You have totally %d tries.\n"
         "==========\n",
         high, number_of_tries);

  /**
   * (2) generate a random number between 1 and high as the secret number
   */
  srand(time(NULL));
  int secret = rand() % high + 1;
  printf("=====Just for Test: secret = %d.=====\n", secret);

  /**
   * (3) ask the player to input a guess
   */
  while (number_of_tries > 0) {
    printf("You still have %d tries.\n"
           "Please input your guess.\n", number_of_tries);

    /**
     * (4) obtain the guessed number,
     * compare it with the secret number,
     * and inform the player of the result
     */
    int guess;
    scanf("%d", &guess);

    if (guess == secret) {
      printf("Congs! You win! \n");
      break;
    } else if (guess > secret) {
      printf("guess > secret.\n");
    } else {
      printf("guess < secret.\n");
    }

    /**
     * (5) repeat (3)-(4) until the player wins or loses
     */
    number_of_tries--;

    if (number_of_tries == 0) {
      printf("Sorry. You Lose!");
    }
  }

  return 0;
}