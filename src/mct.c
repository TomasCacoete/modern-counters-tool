#include <stdio.h>
#include <stdlib.h>

#include "../header/vector.h"

#include "../header/card.h"
#include "../header/hand_player.h"

#define INITIAL_PLAYER_CAPACITY 20

vector* mct_players;

void init_mct(){
    mct_players = init_vector(sizeof(Player), INITIAL_PLAYER_CAPACITY);
}

void init_player(Player* player, double initial_money, Action (*initial_strategy)(Hand hand, Card dealer_card)){
    player->money = initial_money;
    player->strategy = initial_strategy;

    insert_element(mct_players, player);
}

void free_mct(){
    free_vector(mct_players);
}