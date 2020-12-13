#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "structs.h"
#include "card.h"

/**
 * Take a random card from the deck
 * Remove it from the deck
 * Add it to the hand
 * Realloc memory space if necessary
 * 
 * @param hand hand to add to
 * @param deck deck to pull from
 */
void add_card(hand *hand, deck *deck)
{
  time_t t;
  srand((unsigned)(time(&t)));
  int i = (rand() % 52);
  if (!has_available_card(deck))
  {
    printf("No more cards! Game over!\n");
    return;
  }
  while (deck->cards[i].taken)
  {
    i = rand() % 52;
  }
  if (hand->card_count == hand->hand_limit)
  {
    hand->cards = (card *)(realloc(hand->cards, sizeof(card) * (hand->card_count + 2)));
    hand->hand_limit += 2;
  }

  deck->cards[i].taken = true;
  *(hand->cards + hand->card_count) = *(deck->cards + i);
  hand->card_count++;
}

/**
 * Check if a hand contains an ace inside
 * 
 * @param hand hand to check
 * 
 * @return {@code true} if hand contains an ace, {@code false} otherwise
 */
bool contains_ace(hand *hand)
{
  for (int i = 0; i < hand->card_count; i++)
  {
    if (strcmp(hand->cards[i].value, "A") == 0)
    {
      return true;
    }
  }
  return false;
}

/**
 * Check if a hand contains a face card or 10 inside
 * 
 * @param hand hand to check
 * 
 * @return {@code true} if hand contains a face card or 10, {@code false} otherwise
 */
bool contains_face_card(hand *hand)
{
  for (int i = 0; i < hand->card_count; i++)
  {
    if (strcmp(hand->cards[i].value, "J") == 0 || strcmp(hand->cards[i].value, "Q") == 0 || strcmp(hand->cards[i].value, "K") == 0 || strcmp(hand->cards[i].value, "10") == 0)
    {
      return true;
    }
  }
  return false;
}

/**
 * Check if a hand contains a blackjack
 * 
 * @param hand hand to check
 * 
 * @return {@code true} if hand contains a blackjack, {@code false} otherwise
 */
bool contains_blackjack(hand *hand)
{
  if (hand->card_count == 2)
  {
    return contains_face_card(hand) && contains_ace(hand);
  }
  return false;
}

/**
 * Get the value of the hand
 * 
 * @param hand hand to check
 * 
 * @return 21 if blackjack, otherwise the value of the hand calculated from the sum of card values
 */
int get_hand_value(hand *hand)
{
  if (contains_blackjack(hand))
  {
    return 21;
  }
  int values = 0;
  for (int i = 0; i < hand->card_count; i++)
  {
    values += get_card_value(hand->cards[i]);
  }
  if(contains_ace(hand) && values < 11){
    values += 10;
  }
  return values;
}

/**
 * Check if the hand has busted
 * 
 * @param hand hand to check
 * 
 * @return {@code true} if busted, {@code false} otherwise
 */
bool has_busted(hand *hand)
{
  if (get_hand_value(hand) > 21)
  {
    return true;
  }
  return false;
}

/**
 * Sets the hand's held to true
 * 
 * @param hand hand to set
 */
void hold(hand *hand)
{
  hand->held = true;
}

/**
 * Sets the hand's bust to true
 * 
 * @param hand hand to set
 */
void bust(hand *hand)
{
  hand->has_busted = true;
}