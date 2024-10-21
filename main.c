#include <stdio.h>
#include <stdlib.h>

#include "header/vector.h"

#include "header/card.h"
#include "header/shoe.h"
#include "header/player.h"
#include "header/hand.h"
#include "header/settings.h"
#include "header/table.h"
#include "header/blackjack.h"
#include "header/mct.h"


int main(/*int argc, char *argv[]*/){
    init_mct();

    Table table;
    init_table(&table);

    Player p1;
    init_player(&p1, 500);

    Table* aux = (Table*)get(mct_tables, 0);
    aux->shoe.cut_card_pos = 50;

    Player* p_aux = (Player*)get(mct_players, 0);
    join_table(aux, p_aux, 1, dealer_ai);

    play_round(aux);

    free_mct();

    return 0;
}