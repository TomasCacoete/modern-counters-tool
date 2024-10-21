#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "../header/card.h"
#include "../header/player.h"
#include "../header/hand.h"
#include "../header/shoe.h"
#include "../header/settings.h"
#include "../header/table.h"

void deal_initial_round(Table* table);
void play_round(Table* table);

#endif