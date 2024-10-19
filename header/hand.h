#ifndef HAND_PLAYER_H
#define HAND_PLAYER_H

#include "../header/vector.h"

#include "../header/card.h"
#include "../header/player.h"

typedef enum {

    ACTION_HIT,
    ACTION_STAND,
    ACTION_DOUBLE,
    ACTION_SPLIT,
    ACTION_SURRENDER,

} Action;

typedef struct Hand Hand;

typedef struct Hand{

    vector* cards;
    Player* player;
    Action (*strategy)(Hand* hand, Card dealer_card);

} Hand;

void init_hand(Hand** hand_ptr, Player* player, Action (*strategy)(Hand* hand, Card dealer_card));
void free_hand(Hand* hand);

void print_hand(Hand hand);
int get_hand_total(Hand hand);

Action dealer_ai(Hand* hand, Card dealer_card);

#endif