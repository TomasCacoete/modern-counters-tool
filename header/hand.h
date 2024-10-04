#ifndef HAND_H
#define HAND_H

#include "../header/vector.h"

#include "../header/card.h"

#define INITIAL_HAND_SIZE 15

typedef struct {

    vector* cards;

} Hand;

void init_hand(Hand* hand);

void print_hand(Hand hand);
int get_hand_total(Hand hand);

#endif