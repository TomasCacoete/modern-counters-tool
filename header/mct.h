#ifndef MCT_H
#define MCT_H

#include "../header/vector.h"

#include "../header/card.h"
#include "../header/player.h"
#include "../header/hand.h"

extern vector* mct_players;
extern vector* mct_tables;

void init_mct();

void init_player(Player* player, double initial_money);
void init_table(Table* table);

void free_mct();

#endif