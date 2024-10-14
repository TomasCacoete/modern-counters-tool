#ifndef SHOE_H
#define SHOE_H

#include "../header/card.h"
#include "../header/hand_player.h"

typedef struct {

    Card* cards;
    int n_current_cards;
    int n_decks;
    int cut_card_pos;
    double penetration_point;

} Shoe;

void init_shoe(Shoe* shoe, int n_decks, double penetration_point);
void free_shoe(Shoe* shoe);
void shuffle_whole_shoe(Shoe* shoe);
void remove_card_from_shoe(Shoe* shoe, Card card_to_remove);
Card* deal_last_card(Shoe* shoe);
Card* deal_from_shoe(Shoe* shoe,  Hand** table_hands, int n_hands);

#endif