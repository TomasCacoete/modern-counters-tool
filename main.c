#include <stdio.h>

#include "header/playing_card.h"
#include "header/blackjack_hand.h"

int main(){

    Card cards[4] = {
        {Ace, Hearts},
        {Seven, Clubs},
        {Nine, Clubs},
        {Ace, Clubs},
    };

    Hand hand;
    init_hand(&hand, 2);

    for(int i=0; i<4; i++){
        add_card_to_hand(&hand, cards[i]);
    }

    printf("%d\n", get_hand_total(&hand));

    clear_hand(&hand);

    return 0;
}