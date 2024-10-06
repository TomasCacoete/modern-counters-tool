#include <stdio.h>
#include <stdlib.h>

#include "../header/vector.h"

#include "../header/card.h"
#include "../header/hand_player.h"

#define INITIAL_HAND_SIZE 15

void init_hand(Hand** hand_ptr, Player* player){

    *hand_ptr = (Hand*)malloc(sizeof(Hand));
    if(*hand_ptr == NULL){
        fprintf(stderr, "ERROR: Failed to allocate memory for hand\n");
        exit(EXIT_FAILURE);
    }

    (*hand_ptr)->cards = init_vector(sizeof(Card), INITIAL_HAND_SIZE);
    (*hand_ptr)->player = player;
}

void free_hand(Hand* hand){
    free_vector(hand->cards);
    free(hand);
}

void print_hand(Hand hand){
    for(size_t i=0; i<hand.cards->size; i++){
        print_card(*(Card*)get(hand.cards, i));
    }
}

int get_hand_total(Hand hand){

    int hand_total = 0;
    int n_aces = 0;

    for(size_t i=0; i<hand.cards->size; i++){
        Card card = *(Card*)get(hand.cards, i);
        hand_total += get_card_value(card);

        if(card.rank == Ace){
            n_aces++;
        }
    }

    while(n_aces > 0 && hand_total > 21){
        hand_total -= 10;
    }

    return hand_total;
}