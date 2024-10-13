#include <stdio.h>
#include <stdlib.h>

#include "header/vector.h"

#include "header/card.h"
#include "header/shoe.h"
#include "header/hand_player.h"
#include "header/settings.h"
#include "header/table.h"
#include "header/blackjack.h"
#include "header/mct.h"


int main(/*int argc, char *argv[]*/){
    init_mct();

    Table table;
    init_table(&table);

    Player p1;
    init_player(&p1, 500, dealer_ai);
    join_table(&table, &p1, 1);

    deal_initial_round(&table);

    Table* aux = (Table*)get(mct_tables, 0);
    print_table(*aux);

    free_mct();

    return 0;
}