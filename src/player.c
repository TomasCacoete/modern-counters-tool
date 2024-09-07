#include "../header/card.h"
#include "../header/hand.h"

typedef struct {
    
    double money;
    Hand hand;

} Player;


void init_player(Player* player, double buy_in, int player_seat){
    
    player->money = buy_in;
    init_hand(&player->hand, player_seat);
}

void hit(Card* shoe, Hand hand){
    
}