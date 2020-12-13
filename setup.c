#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "structs.h"

/**
 * Setup deck; sets up the deck with all the cards in the deck
 * Sets the suit, value, and taken values of each card being made in the deck
 * Allocates memory for deck (malloc) and returns pointer to deck
 * 
 * @return pointer to the deck in memory 
 * 
 */
deck *setup_deck(void)
{
  deck *card_deck = (deck *)(malloc(sizeof(deck)));
  char *suits[4] = {(char *)"♣", (char *)"❤", (char *)"♠", (char *)"◆"};
  char *values[13] = {(char *)"A", (char *)"2", (char *)"3", (char *)"4", (char *)"5", (char *)"6", (char *)"7", (char *)"8", (char *)"9", (char *)"10", (char *)"J", (char *)"Q", (char *)"K"};
  int count = 0;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 13; j++)
    {
      strcpy(card_deck->cards[count].suit, suits[i]);
      strcpy(card_deck->cards[count].value, values[j]);
      card_deck->cards[count].taken = false;
      count++;
    }
  }
  return card_deck;
}

/**
 * Sets up the hand
 * 
 * Allocates memory for a pointer to a player's hand
 * Allocates memory for the cards within the player's hand
 * Sets default values for the player's card count, hand limit, held, and busted attributes
 * 
 * @returns pointer to the created hand in memory
 */
hand *setup_hand(void)
{
  hand *player_hand = (hand *)(malloc(sizeof(hand)));
  player_hand->cards = (card *)(malloc(sizeof(card) * 2));
  player_hand->card_count = 0;
  player_hand->hand_limit = 2;
  player_hand->held = false;
  player_hand->has_busted = false;
  return player_hand;
}
