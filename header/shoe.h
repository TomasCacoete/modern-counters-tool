#ifndef SHOE_H
#define SHOE_H

#include "card.h"

typedef struct {

    Card* cards;
    int n_current_cards;
    int n_decks;
    int cut_card_pos;

} Shoe;

void init_shoe(Shoe* shoe, int n_decks, double penetration_point);
void free_shoe(Shoe* shoe);
void shuffle_whole_shoe(Shoe* shoe);
Card* deal_from_shoe(Shoe* shoe);

#endif