#ifndef HAND_H
#define HAND_H

#include "card.h"

typedef struct {

    Card* cards;
    int n_current_cards;
    int max_n_cards;
    int seat;

} Hand;

void init_hand(Hand* hand, int player_seat);
void add_card_to_hand(Hand* hand, Card new_card);
void clear_hand(Hand* hand);

int get_hand_total(Hand hand);

#endif