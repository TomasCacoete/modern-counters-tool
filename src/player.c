#include <stdio.h>
#include <stdlib.h>

#include "../header/card.h"
#include "../header/hand.h"
#include "../header/shoe.h"

typedef struct {
    
    double money;
    Hand* hands;
    int n_current_hands;
    int max_n_hands;

} Player;

//Initializes the player with two available hands
void init_player(Player* player, double buy_in, int player_seat){
    
    player->money = buy_in;

    player->hands = (Hand*)malloc(2 * sizeof(Hand)); //2 initial hands to handle splitting
    if(player->hands == NULL){
        perror("Error initializing player");
        exit(EXIT_FAILURE);
    }

    init_hand(&player->hands[0], player_seat);
    init_hand(&player->hands[1], player_seat);

    player->n_current_hands = 2;
    player->max_n_hands = 2;
}

//Adds another hand to the player
void add_hand_to_player(Player* player, Hand new_hand){

    if(player->n_current_hands == player->max_n_hands){
        player->max_n_hands = (int)((player->max_n_hands*3)/2 + 1);

        player->hands = (Hand*)realloc(player->hands, player->max_n_hands * sizeof(Hand));
        if(player->hands == NULL){
            perror("Error reallocating more space for hands");
            exit(EXIT_FAILURE);
        }
    }

    player->hands[player->n_current_hands] = new_hand;
    player->n_current_hands++;
}

//Cleans player's resources including his hands
void end_session(Player* player){

    for(int i=0; i<player->n_current_hands; i++){
        clear_hand(&player->hands[i]);
    }

    free(player->hands);
    player->n_current_hands = 0;
    player->max_n_hands = 0;
}


void hit(Shoe* shoe, Hand* hand){
    
    Card dealt_card = deal_from_shoe(shoe);
    add_card_to_hand(hand, dealt_card);
}