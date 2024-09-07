#include "../header/card.h"
#include "../header/hand.h"
#include "../header/shoe.h"

typedef struct {
    
    double money;
    Hand hand;

} Player;


void init_player(Player* player, double buy_in, int player_seat){
    
    player->money = buy_in;
    init_hand(&player->hand, player_seat);
}

void hit(Shoe* shoe, Hand* hand){
    
    Card dealt_card = deal_from_shoe(shoe);
    add_card_to_hand(hand, dealt_card);
}