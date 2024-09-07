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

    hit(&shoe, &p1.hand);
    hit(&shoe, &p1.hand);
    hit(&shoe, &p1.hand);

    for(int i=0; i<p1.hand.n_current_cards; i++){
        print_card(p1.hand.cards[i]);
    }

    printf("Hand Total: %d\n", get_hand_total(p1.hand));
    
    clear_hand(&p1.hand);
    free_shoe(&shoe);

    return 0;
}