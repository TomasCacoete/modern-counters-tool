#ifndef HAND_PLAYER_H
#define HAND_PLAYER_H

#include "../header/vector.h"

#include "../header/card.h"

typedef struct Hand Hand;
typedef struct Player Player;

typedef enum {

    ACTION_HIT,
    ACTION_STAND,
    ACTION_DOUBLE,
    ACTION_SPLIT,
    ACTION_SURRENDER,

} Action;

struct Hand{

    vector* cards;
    Player* player;

};

struct Player{

    double money;
    Action (*strategy)(Hand hand, Card dealer_card);

};

void init_hand(Hand** hand_ptr, Player* player);
void free_hand(Hand* hand);

void print_hand(Hand hand);
int get_hand_total(Hand hand);

Action dealer_ai(Hand hand, Card dealer_card);

#endif