#include <stdio.h>
#include <stdlib.h>

#include "../header/card.h"
#include "../header/shoe.h"
#include "../header/hand.h"
#include "../header/settings.h"

typedef struct {
    
    Shoe shoe;
    Hand** hands;
    Settings settings;

} Table;

void init_dealer_hand(Table* table){
    init_hand(&table->hands[0]);
    table->hands[0]->player = NULL;
}

void init_table(Table* table){
    init_settings(&table->settings);

    table->hands = (Hand**)malloc((table->settings.max_n_players+1) * sizeof(Hand*));
    if(table->hands == NULL){
        fprintf(stderr, "ERROR: Failed to allocate memory for table\n");
        exit(EXIT_FAILURE);
    }

    init_dealer_hand(table);
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