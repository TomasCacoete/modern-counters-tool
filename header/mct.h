#ifndef MCT_H
#define MCT_H

#include "../header/vector.h"

#include "../header/card.h"
#include "../header/hand_player.h"

extern vector* mct_players;
extern vector* mct_tables;

void init_mct();

void init_player(Player* player, double initial_money, Action (*initial_strategy)(Hand hand, Card dealer_card));
void init_table(Table* table);

void free_mct();

#endif