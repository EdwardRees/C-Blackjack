#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdbool.h>

/**
 * Card structure
 * 
 * Contains a suit, value, and whether it has been taken already
 */
typedef struct card
{
  char suit[4];
  char value[3];
  bool taken;
} card;

/**
 * Hand structure
 * 
 * Contains a pointer to all the cards, a card count, hand limit, and whether the player has held or busted
 */
typedef struct hand
{
  card *cards;
  int card_count;
  int hand_limit;
  bool held;
  bool has_busted;
} hand;

/**
 * Deck structure
 * 
 * Contains the 52 cards
 */
typedef struct deck
{
  card cards[52];
} deck;

#endif // STRUCTS_H