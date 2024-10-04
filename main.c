#include <stdio.h>

#include "header/vector.h"

#include "header/card.h"
#include "header/shoe.h"
#include "header/hand.h"
#include "header/player.h"
#include "header/settings.h"
#include "header/table.h"

int main(/*int argc, char *argv[]*/){

    Table table;
    init_table(&table);

    Card dealt_card = deal_from_shoe(&table.shoe);
    insert_element(table.hands[0]->cards, &dealt_card);
    dealt_card = deal_from_shoe(&table.shoe);
    insert_element(table.hands[0]->cards, &dealt_card);

    print_hand(*table.hands[0]);

    free_table(&table);

    return 0;
}