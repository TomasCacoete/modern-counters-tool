#include <stdio.h>

#include "header/card.h"
#include "header/hand.h"
#include "header/shoe.h"

int main(){

    Shoe shoe;
    init_shoe(&shoe, 1);

    for(int i=0; i<N_CARDS_IN_DECK; i++){
        print_card(shoe.cards[i]);
    }

    free_shoe(&shoe);

    return 0;
}