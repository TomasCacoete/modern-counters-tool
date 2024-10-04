#ifndef TABLE_H
#define TABLE_H

typedef struct {
    
    Shoe shoe;
    Hand** hands;
    Settings settings;

} Table;

void init_dealer_hand(Table* table);
void init_table(Table* table);
void free_table(Table* table);

#endif