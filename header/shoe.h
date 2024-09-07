#ifndef SHOE_H
#define SHOE_H

#include "card.h"

typedef struct {

    Card* cards;
    int n_current_cards;
    int n_decks;

} Shoe;

void init_shoe(Shoe* shoe, int n_decks);
void free_shoe(Shoe* shoe);
void shuffle_whole_shoe(Shoe* shoe);


#endif