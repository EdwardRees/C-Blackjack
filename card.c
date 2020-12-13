#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "structs.h"

/**
 * Get the card value from a given card
 * 
 * @param card card to get the value of
 * 
 * @return card value; 11 if Ace, 10 if face card, numeric value otherwise
 */
int get_card_value(card card)
{
  if (strcmp(card.value, "A") == 0)
  {
    return 11;
  }
  else if (strcmp(card.value, "K") == 0 || strcmp(card.value, "Q") == 0 || strcmp(card.value, "J") == 0)
  {
    return 10;
  }
  return atoi(card.value);
}

/**
 * Check if deck has an available card still
 * 
 * @param deck deck to check from
 * 
 * @return {@code true} if still possible to play, {@code false} otherwise
 */
bool has_available_card(deck *deck)
{
  for (int i = 0; i < 52; i++)
  {
    if (deck->cards[i].taken == false)
    {
      return true;
    }
  }
  return false;
}
