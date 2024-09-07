#ifndef BLACKJACK_HAND_H
#define BLACKJACK_HAND_H

#include "playing_card.h"

typedef struct {

    Card* cards;
    int n_current_cards;
    int max_n_cards;

} Hand;

void init_hand(Hand* hand, int initialSize);
void add_card_to_hand(Hand* hand, Card new_card);
void clear_hand(Hand* hand);

int get_hand_total(Hand* hand);

#endif