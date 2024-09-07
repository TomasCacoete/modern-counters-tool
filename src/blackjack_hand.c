#include <stdio.h>
#include <stdlib.h>

#include "../header/playing_card.h"

typedef struct {

    Card* cards;
    int n_current_cards;
    int max_n_cards;

} Hand;

//Initializes hand by allocating memory for the cards and setting counters to 0
void init_hand(Hand* hand, int initialSize){

    hand->cards = (Card*)malloc(initialSize * sizeof(Card));
    if(hand->cards == NULL){
        perror("Error initializing hand");
        exit(EXIT_FAILURE);
    }

    hand->n_current_cards = 0;
    hand->max_n_cards = initialSize;
}

//Adds a card to a hand. If the hand max size is reached it is extended
void add_card_to_hand(Hand* hand, Card new_card){

    if(hand->n_current_cards == hand->max_n_cards){
        hand->max_n_cards = (int)((hand->max_n_cards*3)/2 + 1);

        hand->cards = (Card*)realloc(hand->cards, hand->max_n_cards * sizeof(Card));
        if(hand->cards == NULL){
            perror("Error reallocating more space for hand");
            exit(EXIT_FAILURE);
        }
    }

    hand->cards[hand->n_current_cards] = new_card;
    hand->n_current_cards++;
}

//Clears hand by freeing the memory and setting counters to 0
void clear_hand(Hand* hand){

    free(hand->cards);
    hand->n_current_cards = 0;
    hand->max_n_cards = 0;
}

//Gets the hand total of a hand
int get_hand_total(Hand* hand){

    int hand_total = 0;
    int n_aces = 0;

    for(int i=0; i<hand->n_current_cards; i++){
        hand_total += hand->cards[i].rank;

        if(hand->cards[i].rank == Ace){
            n_aces++;
        }
    }

    while(n_aces > 0 && hand_total > 21){
        hand_total -= 10;
    }

    return hand_total;
}