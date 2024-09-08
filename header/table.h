#ifndef TABLE_H
#define TABLE_H

#include "card.h"
#include "hand.h"
#include "shoe.h"
#include "player.h"
#include "settings.h"

typedef struct {

    Shoe shoe;
    Player dealer;
    Player** players;
    Settings settings;

} Table;

void init_table(Table* table);
void join_table(Table* table, Player* player, int player_seat);
void free_table(Table* table);

#endif