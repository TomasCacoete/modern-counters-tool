#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "../header/card.h"
#include "../header/shoe.h"
#include "../header/player.h"
#include "../header/hand.h"
#include "../header/settings.h"

#define DEALER_SEAT 0

typedef struct {
    
    Shoe shoe;
    Hand** hands;
    Settings settings;

} Table;


void init_dealer(Table* table){
    Player* dealer = (Player*)malloc(sizeof(Player));
    if(dealer == NULL){
        fprintf(stderr, "ERROR: Failed to allocate memory for dealer\n");
        exit(EXIT_FAILURE);
    }

    dealer->money = INFINITY;

    init_hand(&table->hands[DEALER_SEAT], dealer, dealer_ai);
}

void init_table_data(Table* table){
    init_settings(&table->settings);

    table->hands = (Hand**)malloc((table->settings.max_n_players+1) * sizeof(Hand*));
    if(table->hands == NULL){
        fprintf(stderr, "ERROR: Failed to allocate memory for table\n");
        exit(EXIT_FAILURE);
    }

    init_dealer(table);
    for(int i=1; i<table->settings.max_n_players+1; i++){
        table->hands[i] = NULL;
    }

    init_shoe(&table->shoe, table->settings.n_decks, table->settings.penetration_point);
    //shuffle_whole_shoe(&table->shoe);
}

void free_table(Table* table){
    free_shoe(&table->shoe);

    free(table->hands[0]->player);
    free_hand(table->hands[0]);

    for(int i=1; i<table->settings.max_n_players+1; i++){

        if(table->hands[i] != NULL){ 
            free_hand(table->hands[i]);
        }
    }

    free(table->hands);
}

void print_table(Table table, bool SHOW_FIRST_DEALER_CARD){
    printf("---------------------------\n");
    printf("DEALER: ");

    if(SHOW_FIRST_DEALER_CARD){
        printf("Hand Total: %d\n", get_hand_total(*table.hands[0]));
        print_hand(*table.hands[0]);
        
    } else{
        printf("Hand Total: %d\n", get_card_value(*(Card*)get(table.hands[0]->cards, 1)));
        printf("Flipped Card\n");
        print_card(*(Card*)get(table.hands[0]->cards, 1));
    }

    printf("---------------------------\n");

    for(int i=1; i<table.settings.max_n_players+1; i++){
        if(table.hands[i] != NULL){
            printf("PLAYER %d: Hand Total: %d\n", i, get_hand_total(*table.hands[i]));
            print_hand(*table.hands[i]);
            printf("---------------------------\n");
        }
    }
}


void join_table(Table* table, Player* player, int player_seat, Action (*strategy)(Hand* hand, Card dealer_card)){

    if(player_seat < 0 || player_seat > table->settings.max_n_players){
        fprintf(stderr, "ERROR: Invalid seat number\n");
        exit(EXIT_FAILURE);
    }

    if(table->hands[player_seat] != NULL){
        fprintf(stderr, "ERROR: Seat %d is already occupied\n", player_seat);
        exit(EXIT_FAILURE);
    }

    init_hand(&table->hands[player_seat], player, strategy);
}