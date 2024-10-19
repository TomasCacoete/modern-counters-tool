#include "../header/card.h"
#include "../header/hand_player.h"
#include "../header/shoe.h"
#include "../header/settings.h"
#include "../header/table.h"

void deal_initial_round(Table* table){
    for(int k=0; k<2; k++){
        for(int i=0; i<table->settings.max_n_players+1; i++){
            if(table->hands[i] != NULL){
                Card* dealt_card = deal_from_shoe(&table->shoe, table->hands, table->settings.max_n_players+1);
                insert_element(table->hands[i]->cards, dealt_card);
            }
        }
    }
}

void play_hand(Hand** hand, Card dealer_card){
    Action player_decision;
    do {

        player_decision = (*hand)->player->strategy(**hand, dealer_card);

    } while(player_decision != ACTION_STAND);
}

void play_round(Table* table){
    deal_initial_round(table);
    print_table(*table, false);
    
    for(int i=1; i<table->settings.max_n_players+1; i++){
        if(table->hands[i] != NULL){

        }
    }
}