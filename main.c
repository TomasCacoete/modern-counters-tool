#include <stdio.h>
#include <stdlib.h>

#include "header/vector.h"

#include "header/card.h"
#include "header/shoe.h"
#include "header/hand_player.h"
#include "header/settings.h"
#include "header/table.h"
#include "header/blackjack.h"

int main(/*int argc, char *argv[]*/){

    Table table;
    init_table(&table);
    printf("%d\n", table.shoe.cut_card_pos);

    Player* p1 = (Player*)malloc(sizeof(Player));
    p1->strategy = dealer_ai;
    join_table(&table, p1, 1);

    shuffle_whole_shoe(&table.shoe);
    deal_initial_round(&table);

    print_table(table);

    free_table(&table);

    return 0;
}