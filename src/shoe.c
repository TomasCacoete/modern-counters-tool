#include <stdio.h>
#include <stdlib.h>

#include "../header/card.h"
#include "../header/hand.h"

#define MISPLACEMENT_FACTOR 0.05

typedef struct {

    Card* cards;
    int n_current_cards;
    int n_decks;
    int cut_card_pos; //is between cards on index n-1 and n
    double penetration_point;

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

    return (rand() % (max-min+1)) + min;
}

//TODO: Change n_total_cards to n_current_cards?
int set_cut_card_pos(Shoe* shoe){

    if(shoe->penetration_point >= 1 || shoe->penetration_point <= 0){
        return -1;
    }

    int n_total_cards = N_CARDS_IN_DECK * shoe->n_decks;

    int target_position = n_total_cards*shoe->penetration_point;
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
    shoe->penetration_point = penetration_point;
    shoe->cut_card_pos = set_cut_card_pos(shoe);

    populate_shoe(shoe);
}

//Frees the shoe's memory
void free_shoe(Shoe* shoe){
    free(shoe->cards);
}


void swap_cards(Card* card_1, Card* card_2){

    Card temp = *card_1;
    *card_1 = *card_2;
    *card_2 = temp;
}

void shuffle_whole_shoe(Shoe* shoe){

    for(int i=shoe->n_current_cards - 1; i>0; i--){
        int j = rand() % (i+1);
        swap_cards(&shoe->cards[i], &shoe->cards[j]);
    }
}

//places the last card of the shoe in the position of the card to remove
void remove_card_from_shoe(Shoe* shoe, Card card_to_remove){
    for(int i=0; i<shoe->n_current_cards; i++){
        if(cards_equal(shoe->cards[i], card_to_remove)){
            swap_cards(&shoe->cards[i], &shoe->cards[shoe->n_current_cards-1]);
            shoe->n_current_cards--;
            return;
        }
    }
}


void handle_reaching_cut_card(Shoe* shoe, Hand** table_hands, int n_hands){
    //initialize the new shoe
    Shoe new_shoe;
    init_shoe(&new_shoe, shoe->n_decks, shoe->penetration_point);

    //remove the cards that are currently on the table from the new shoe to avoid repeated cards
    for(int i=0; i<n_hands; i++){
        if(table_hands[i] != NULL){
            for(size_t j=0; j<table_hands[i]->cards->size; j++){
                Card card = *(Card*)get(table_hands[i]->cards, j);
                remove_card_from_shoe(&new_shoe, card);
            }
        }
    }

    //shuffle the new shoe
    printf("SHUFFLING FIRST %d CARDS\n", new_shoe.n_current_cards);
    shuffle_whole_shoe(&new_shoe);

    free_shoe(shoe);
    *shoe = new_shoe;
}

//Takes the last card from the shoe and returns it
Card* deal_last_card(Shoe* shoe){
    if(shoe->n_current_cards == 0){
        fprintf(stderr, "ERROR: No more cards to deal from the shoe\n");
        exit(EXIT_FAILURE);
    }

    Card* last_card = &shoe->cards[shoe->n_current_cards-1];
    shoe->n_current_cards--;
    
    return last_card;
}

Card* deal_from_shoe(Shoe* shoe,  Hand** table_hands, int n_hands){
    if(shoe->n_current_cards == 0){
        fprintf(stderr, "ERROR: No more cards to deal from the shoe\n");
        exit(EXIT_FAILURE);
    }

    if(shoe->n_current_cards == shoe->cut_card_pos){
        handle_reaching_cut_card(shoe, table_hands, n_hands);
    }

    return deal_last_card(shoe);
}