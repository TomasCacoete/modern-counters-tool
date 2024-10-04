#include <stdio.h>

#include "header/vector.h"

#include "header/card.h"
#include "header/shoe.h"
#include "header/hand.h"

int main(/*int argc, char *argv[]*/){

    Hand hand;
    init_hand(&hand);

    Card aux = {Ace, 10};
    insert_element(hand.cards, &aux);

    for(size_t i=0; i<hand.cards->size; i++){
        print_card(*(Card*)get(hand.cards, i));
    }

    free_vector(hand.cards);

    return 0;
}