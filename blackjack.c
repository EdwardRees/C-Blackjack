#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "structs.h"
#include "printer.h"
#include "setup.h"
#include "card.h"
#include "hand.h"
#include "game.h"

/**
 * Print out the options for the command line arguments
 */
void print_options(void)
{
  printf("./blackjack interactive: To play the interactive version with two players\n");
  printf("./blackjack sp show: To play the single player version against a computer, with showing the computer's cards on\n");
  printf("./blackjack sp: To play the single player version against a computer, with showing the computer's cards off\n");
  printf("./blackjack single-player show: To play the single player version against a computer, with showing the computer's cards on\n");
  printf("./blackjack single-player: To play the single player version against a computer, with showing the computer's cards off\n");
  printf("./blackjack help: To show this help menu\n");
}

/**
 * Main running method
 * 
 * @return 0
 */
int main(int argc, char *argv[])
{
  deck *card_deck = setup_deck();
  hand *p1_hand = setup_hand();
  hand *p2_hand = setup_hand();
  if (argc == 1)
  {
    printf("No mode given, defaulting to game against computer\n");
    single_player(card_deck, p1_hand, p2_hand, false);
  }
  else
  {
    if (strcmp(argv[1], "interactive") == 0)
    {
      printf("Running two player interactive mode!\n");
      interactive(card_deck, p1_hand, p2_hand);
    }
    else if (strcmp(argv[1], "sp") == 0 || strcmp(argv[1], "single-player") == 0)
    {
      bool show_hand = false;
      if (argc == 3)
      {
        show_hand = strcmp(argv[2], "show") == 0;
      }
      printf("Running single player mode!\n");
      single_player(card_deck, p1_hand, p2_hand, show_hand);
    }
    else if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "h") == 0)
    {
      print_options();
    }
  }

  free(p1_hand->cards);
  free(p1_hand);
  free(p2_hand->cards);
  free(p2_hand);
  free(card_deck);
  return 0;
}
