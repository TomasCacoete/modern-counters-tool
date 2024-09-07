#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../header/card.h"

typedef struct {

    Card* cards;
    int n_current_cards;
    int n_decks;

} Shoe;

void populate_shoe(Shoe* shoe){
    int index = 0;

    for(int decks=0; decks<shoe->n_decks; decks++){
        for(int suit=0; suit<N_SUITS; suit++){
            for(int rank=0; rank<N_RANKS; rank++){

                Card new_card = {rank+2, suit};
                shoe->cards[index++] = new_card;
            }
        }
    }
}

void init_shoe(Shoe* shoe, int n_decks){

    shoe->cards = (Card*)malloc(n_decks*N_CARDS_IN_DECK * sizeof(Card));
    if(shoe->cards == NULL){
        perror("Error initializing shoe");
        exit(EXIT_FAILURE);
    }

    shoe->n_current_cards = n_decks*N_CARDS_IN_DECK;
    shoe->n_decks = n_decks;

    populate_shoe(shoe);
}

void free_shoe(Shoe* shoe){

    free(shoe->cards);
    shoe->n_current_cards = 0;
    shoe->n_decks = 0;
}


void swap_cards(Card* card_1, Card* card_2){

    Card temp = *card_1;
    *card_1 = *card_2;
    *card_2 = temp;
}

void shuffle_whole_shoe(Shoe* shoe){
    srand(time(NULL));

    for(int i=shoe->n_decks*N_CARDS_IN_DECK - 1; i>0; i--){
        int j = rand() % (i+1);
        swap_cards(&shoe->cards[i], &shoe->cards[j]);
    }
}

Card deal_from_shoe(Shoe* shoe){
    Card last_card = shoe->cards[shoe->n_current_cards-1];

    Card null_card = {0,0};
    shoe->cards[shoe->n_current_cards-1] = null_card;
    shoe->n_current_cards--;
    
    return last_card;
}