#include "../header/card.h"
#include "../header/hand.h"
#include "../header/shoe.h"
#include "../header/settings.h"
#include "../header/table.h"

void deal_initial_round(Table* table){
    for(int k=0; k<2; k++){
        for(int i=0; i<table->settings.max_n_players+1; i++){
            if(table->hands[i] != NULL){
                Card dealt_card = deal_from_shoe(&table->shoe);
                insert_element(table->hands[i]->cards, &dealt_card);
            }
        }
    }
}