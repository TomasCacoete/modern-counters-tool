#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../header/card.h"
#include "../header/hand.h"
#include "../header/shoe.h"
#include "../header/player.h"
#include "../header/settings.h"

#define DEALER_SEAT 0

typedef struct {

    Shoe shoe;
    Player dealer;
    Player** players;
    Settings settings;

} Table;

void init_dealer(Player* dealer){

    dealer->money = INFINITY;
    dealer->hands = (Hand*)malloc(1 * sizeof(Hand)); //dealer can only ever have one hand
    if(dealer->hands == NULL){
        perror("Error initializing dealer");
        exit(EXIT_FAILURE);
    }

    init_hand(&dealer->hands[0], DEALER_SEAT); //dealer is always at seat 0
    dealer->n_current_hands = 1;
    dealer->max_n_hands = 1;
}

void init_table(Table* table){
    init_settings(&table->settings);

    table->players = (Player**)malloc((table->settings.max_n_players+1) * sizeof(Player*));
    if(table->players == NULL){
        perror("Error initializing table");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<table->settings.max_n_players+1; i++){
        table->players[i] = NULL;
    }

    table->players[0] = &table->dealer;
    init_dealer(&table->dealer);

    init_shoe(&table->shoe, table->settings.n_decks);
}

void free_table(Table* table){
    free_shoe(&table->shoe);
    end_session(&table->dealer);

    for(int i=1; i<table->settings.max_n_players+1; i++){
        if(table->players[i] != NULL){
            end_session(table->players[i]);
        }
    }

    free(table->players);
}

void join_table(Table* table, Player* player, int player_seat){

    if(player_seat < 0 || player_seat >= table->settings.max_n_players){
        printf("Invalid seat number\n");
        return;
    }

    if(table->players[player_seat] != NULL){
        printf("Seat %d is already occupied\n", player_seat);
        return;
    }
    
    init_player(player, 500, player_seat); //TODO: The player should be able to define the buy in value
    table->players[player_seat] = player;
}

void deal_initial_round(Table* table){

    for(int i=0; i<2; i++){
        add_card_to_hand(&table->dealer.hands[0], deal_from_shoe(&table->shoe));
        
    }
}