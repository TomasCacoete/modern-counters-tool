#include "../header/vector.h"

#include "../header/card.h"
#include "../header/player.h"

#define INITIAL_HAND_SIZE 15

typedef struct {

    vector* cards;
    Player* player;

} Hand;

void init_hand(Hand* hand){
    hand->cards = init_vector(sizeof(Card), INITIAL_HAND_SIZE);
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
        Card card = *(Card*)get(hand.cards->elements, i);
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