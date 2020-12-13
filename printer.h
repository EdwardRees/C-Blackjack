#ifndef PRINTER_H_
#define PRINTER_H_ 

#include "structs.h"

void print_card(card card);

char *get_print_card(card card);

void print_deck(deck *card_deck);

void print_hand(hand* player_hand);

#endif //PRINTER_H
