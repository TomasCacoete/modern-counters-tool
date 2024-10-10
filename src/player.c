#include <stdio.h>
#include <stdlib.h>

#include "../header/hand_player.h"

Action dealer_ai(Hand hand, Card dealer_card){
    (void)dealer_card;

    if(get_hand_total(hand) > 17){
        return ACTION_STAND;

    } else {
        return ACTION_HIT;
    }
}