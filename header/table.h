#ifndef TABLE_H
#define TABLE_H

#include "../header/settings.h"
#include "../header/shoe.h"

typedef struct {
    
    Shoe shoe;
    Hand** hands;
    Settings settings;

} Table;

void init_table_data(Table* table);
void free_table(Table* table);
void print_table(Table table);

void join_table(Table* table, Player* player, int player_seat, Action (*strategy)(Hand* hand, Card dealer_card));
void end_session(Table* table, Player* player);

#endif