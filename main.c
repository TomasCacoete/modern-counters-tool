#include <stdio.h>

#include "header/card.h"
#include "header/hand.h"
#include "header/shoe.h"
#include "header/player.h"
#include "header/settings.h"
#include "header/table.h"

int main(/*int argc, char *argv[]*/){

    Table table;
    init_table(&table);

    Player p1;
    join_table(&table, &p1, 1);

    Player p2;
    join_table(&table, &p2, -1);

    for(int i=0; i<table.settings.max_n_players+1; i++){
        if(table.players[i] != NULL){
            printf("%f\n", table.players[i]->money);
        } else{
            printf("NULL player\n");
        }
    }


    free_table(&table);

    return 0;
}