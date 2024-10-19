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

    Table t1;
    init_table(&t1);

    Table* aux = (Table*)get(mct_tables, 0);
    aux->shoe.cut_card_pos = 49;

    Player p1;
    init_player(&p1, 500, dealer_ai);
    join_table(aux, &p1, 1);
    
    play_round(aux);
    

    free_mct();

    return 0;
}

/*

TODO:
Change the strategy function to be on the struct of the hand instead of the player.
This makes it possible for a player to use different strategies on different hands

*/