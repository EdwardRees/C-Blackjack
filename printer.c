#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

/**
 * Print out a string containing the whole card values;
 * 
 * Mallocs a string for the card to print 
 * 
 * @param card card to print out
 * 
 * @return string containing the suit and value
 */
char *get_print_card(card card)
{
  char *str = (char *)(malloc(sizeof(char) * 5));
  strcpy(str, card.suit);
  strcat(str, card.value);
  return str;
}

/**
 * Print out the deck; Prints out each card in the deck, one by one
 * 
 * @param card_deck deck to print from
 */
void print_deck(deck *card_deck)
{
  printf("Current Deck:\n");
  for (int i = 0; i < 52; i++)
  {
    if (card_deck->cards[i].taken)
    {
      continue;
    }
    char *str = get_print_card(card_deck->cards[i]);
    printf("%s ", str);
    if ((i + 1) % 13 == 0)
    {
      printf("\n");
    }
    free(str);
  }
}

/**
 * print out an individual card; calls @see get_print_card
 * 
 * Frees card that was printed after printing it
 * 
 * @param card card to print
 */
void print_card(card card)
{
  char *chosen_card = get_print_card(card);
  printf("%s ", chosen_card);
  free(chosen_card);
}

/**
 * Prints out the hand
 * 
 * @param player_hand player hand to print
 */
void print_hand(hand *player_hand)
{
  for (int i = 0; i < player_hand->card_count; i++)
  {
    print_card(player_hand->cards[i]);
    if ((i + 1) % 13 == 0)
    {
      printf("\n");
    }
  }
}
