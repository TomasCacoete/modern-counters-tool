#ifndef TABLE_H
#define TABLE_H

typedef struct {
    
    Shoe shoe;
    Hand** hands;
    Settings settings;

} Table;

void init_table(Table* table);
void free_table(Table* table);
void print_table(Table table);

void join_table(Table* table, Player* player, int player_seat);
void end_session(Table* table, Player* player);

#endif