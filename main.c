#include <stdio.h>

#include "header/vector.h"

#include "header/card.h"
#include "header/shoe.h"
#include "header/hand.h"
#include "header/player.h"

int main(/*int argc, char *argv[]*/){

    Hand hand;
    init_hand(&hand);

    Card aux = {Ace, 10};
    insert_element(hand.cards, &aux);


    free_vector(hand.cards);

    return 0;
}