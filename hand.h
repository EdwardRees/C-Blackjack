#ifndef HAND_H_
#define HAND_H_

#include "structs.h"

void add_card(hand *hand, deck *deck);
int get_hand_value(hand *hand);
bool contains_ace(hand *hand);
bool contains_face_card(hand *hand);
bool contains_blackjack(hand *hand);
bool has_busted(hand *hand);
void hold(hand *hand);
void bust(hand *hand);

#endif // HAND_H_