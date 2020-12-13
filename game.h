#ifndef GAME_H_
#define GAME_H_

#include "structs.h"

void print_menu(void);
void interactive(deck* deck, hand* player1, hand* player2);
void single_player(deck* deck, hand* player, hand* cpu, bool show_hand);

#endif // GAME_H_