#include <stdio.h>

#include "header/vector.h"

#include "header/card.h"
#include "header/shoe.h"
#include "header/hand.h"
#include "header/player.h"
#include "header/settings.h"
#include "header/table.h"
#include "header/blackjack.h"

int main(/*int argc, char *argv[]*/){

    Table table;
    init_table(&table);

    Player p1;
    p1.strategy = dealer_ai;
    join_table(&table, &p1, 1);

    shuffle_whole_shoe(&table.shoe);
    deal_initial_round(&table);

    print_table(table);

    //Card dealer_card = *(Card*)get(table.hands[0]->cards->elements, 0);
    //Hand dealer_hand = *table.hands[0];
    //printf("%d\n", p1.strategy(dealer_hand, dealer_card));

    free_table(&table);

    return 0;
}