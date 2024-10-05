#ifndef PLAYER_H
#define PLAYER_H

#include "../header/card.h"

struct Hand;

typedef enum {

    ACTION_HIT,
    ACTION_STAND,
    ACTION_DOUBLE,
    ACTION_SPLIT,
    ACTION_SURRENDER,

} Action;

typedef struct {

    double money;
    Action (*strategy)(struct Hand* hand, Card dealer_card);

} Player;

Action dealer_ai(struct Hand* hand, Card dealer_card);

#endif