#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "hand.h"
#include "shoe.h"

typedef struct {
    
    double money;
    Hand hand;

} Player;

void init_player(Player* player, double buy_in, int player_seat);
void hit(Shoe* shoe, Hand* hand);

#endif