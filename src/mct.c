#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../header/vector.h"

#include "../header/card.h"
#include "../header/hand_player.h"
#include "../header/table.h"

#define INITIAL_PLAYER_CAPACITY 20
#define INITIAL_TABLE_CAPACITY 5

vector* mct_players;
vector* mct_tables;

void init_mct(){
    srand(time(NULL));
    mct_players = init_vector(sizeof(Player), INITIAL_PLAYER_CAPACITY);
    mct_tables = init_vector(sizeof(Table), INITIAL_TABLE_CAPACITY);
}

void init_player(Player* player, double initial_money, Action (*initial_strategy)(Hand hand, Card dealer_card)){
    player->money = initial_money;
    player->strategy = initial_strategy;

    insert_element(mct_players, player);
}

void init_table(Table* table){
    init_table_data(table);

    insert_element(mct_tables, table);
}

void free_mct(){
    free_vector(mct_players);

    for(size_t i=0; i<mct_tables->size; i++){
        Table* t_aux = (Table*)get(mct_tables, i);
        free_table(t_aux);
    }
    free_vector(mct_tables);
}