#include "../header/card.h"
#include "../header/hand.h"
#include "../header/player.h"

Action dealer_ai(struct Hand* hand, Card dealer_card){
    if(get_hand_total(*hand) > 17){
        return ACTION_STAND;

    } else {
        return ACTION_HIT;
    }
}