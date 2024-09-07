#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "hand.h"
#include "shoe.h"

typedef struct {
    
    double money;
    Hand* hands;
    int n_current_hands;
    int max_n_hands;

} Player;

void init_player(Player* player, double buy_in, int player_seat);
void add_hand_to_player(Player* player, Hand new_hand);
void end_session(Player* player);
void hit(Shoe* shoe, Hand* hand);

#endif