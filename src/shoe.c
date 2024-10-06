#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../header/card.h"

#define MISPLACEMENT_FACTOR 0.05

typedef struct {

    Card* cards;
    int n_current_cards;
    int n_decks;
    int cut_card_pos;

} Shoe;

//Fills the shoe with cards ordered by suit and then by rank
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

int get_random_in_range(int min, int max){

    srand(time(NULL));
    return (rand() % (max-min+1)) + min;
}

int set_cut_card_pos(Shoe* shoe, double penetration_point){

    if(penetration_point >= 1 || penetration_point <= 0){
        return -1;
    }

    int n_total_cards = N_CARDS_IN_DECK * shoe->n_decks;

    int target_position = n_total_cards*penetration_point;
    int misplacement_factor = n_total_cards*MISPLACEMENT_FACTOR;

    int misplacement_amount = get_random_in_range(-misplacement_factor, misplacement_factor);

    int cut_card_pos = target_position + misplacement_amount;

    if(cut_card_pos < 0 || cut_card_pos >= n_total_cards){
        cut_card_pos = -1;
    }

    return cut_card_pos;
}

//Initializes the shoe
void init_shoe(Shoe* shoe, int n_decks, double penetration_point){

    shoe->cards = (Card*)malloc(n_decks*N_CARDS_IN_DECK * sizeof(Card));
    if(shoe->cards == NULL){
        fprintf(stderr, "ERROR: Failed to allocate memory for shoe\n");
        exit(EXIT_FAILURE);
    }

    shoe->n_current_cards = n_decks*N_CARDS_IN_DECK;
    shoe->n_decks = n_decks;
    shoe->cut_card_pos = set_cut_card_pos(shoe, penetration_point);

    populate_shoe(shoe);
}

//Frees the shoe's memory
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

//Takes the last card from the shoe and returns it
Card deal_from_shoe(Shoe* shoe){
    Card last_card = shoe->cards[shoe->n_current_cards-1];
    shoe->n_current_cards--;
    
    return last_card;
}