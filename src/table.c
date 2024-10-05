#include <stdio.h>
#include <stdlib.h>

#include "../header/card.h"
#include "../header/shoe.h"
#include "../header/hand.h"
#include "../header/player.h"
#include "../header/settings.h"

#define DEALER_SEAT 0

typedef struct {
    
    Shoe shoe;
    Hand** hands;
    Settings settings;

} Table;


void init_table(Table* table){
    init_settings(&table->settings);

    table->hands = (Hand**)malloc((table->settings.max_n_players+1) * sizeof(Hand*));
    if(table->hands == NULL){
        fprintf(stderr, "ERROR: Failed to allocate memory for table\n");
        exit(EXIT_FAILURE);
    }

    init_hand(&table->hands[DEALER_SEAT], NULL); //initializes the dealer hand
    table->hands[DEALER_SEAT]->player->strategy = dealer_ai;

    for(int i=1; i<table->settings.max_n_players+1; i++){
        table->hands[i] = NULL;
    }

    init_shoe(&table->shoe, table->settings.n_decks);
}

void free_table(Table* table){
    free_shoe(&table->shoe);

    free_hand(table->hands[0]);
    for(int i=1; i<table->settings.max_n_players+1; i++){
        if(table->hands[i] != NULL){
            free_hand(table->hands[i]);
        }
    }

    free(table->hands);
}

void print_table(Table table){
    printf("---------------------------\n");
    printf("DEALER:\n");
    print_hand(*table.hands[0]);
    printf("---------------------------\n");
    for(int i=1; i<table.settings.max_n_players+1; i++){
        if(table.hands[i] != NULL){
            printf("PLAYER %d: Hand Total: %d\n", i, get_hand_total(*table.hands[i]));
            print_hand(*table.hands[i]);
            printf("---------------------------\n");
        }
    }
}

void join_table(Table* table, Player* player, int player_seat){

    if(player_seat < 0 || player_seat > table->settings.max_n_players){
        fprintf(stderr, "ERROR: Invalid seat number\n");
        exit(EXIT_FAILURE);
    }

    if(table->hands[player_seat] != NULL){
        fprintf(stderr, "ERROR: Seat %d is already occupied\n", player_seat);
        exit(EXIT_FAILURE);
    }

    init_hand(&table->hands[player_seat], player);
    
}