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
    join_table(&table, &p1, 1);

    Player p2;
    join_table(&table, &p2, 4);

    join_table(&table, &p1, 2);

    deal_initial_round(&table);

    print_table(table);


    free_table(&table);

    return 0;
}