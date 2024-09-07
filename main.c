#include <stdio.h>

#include "header/card.h"
#include "header/hand.h"
#include "header/shoe.h"
#include "header/player.h"

int main(){

    Shoe shoe;
    init_shoe(&shoe, 1);

    Player p1;
    init_player(&p1, 500, 2);

    add_card_to_hand(&p1.hands[0], deal_from_shoe(&shoe));
    add_card_to_hand(&p1.hands[1], deal_from_shoe(&shoe));

    Hand new_hand;
    init_hand(&new_hand, 3);

    add_hand_to_player(&p1, new_hand);
    add_card_to_hand(&p1.hands[2], deal_from_shoe(&shoe));

    print_hand(p1.hands[0]);
    print_hand(p1.hands[1]);
    print_hand(p1.hands[2]);
    printf("-------------------------\n");

    for(int i=0; i<N_CARDS_IN_DECK; i++){
        print_card(shoe.cards[i]);
    }

    end_session(&p1);
    free_shoe(&shoe);

    return 0;
}