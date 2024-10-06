#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N_CARDS_IN_DECK 52
#define N_SUITS 4
#define N_RANKS 13

typedef enum {

    Spades = 0,
    Hearts = 1,
    Diamonds = 2,
    Clubs = 3,

} Suit;

typedef enum {

    Two = 2,
    Three = 3,
    Four = 4,
    Five = 5,
    Six = 6,
    Seven = 7,
    Eight = 8,
    Nine = 9,
    Ten = 10,
    Jack = 11,
    Queen = 12,
    King = 13,
    Ace = 14,

} Rank;

typedef struct {

    Rank rank;
    Suit suit;
    
} Card;

//Gets the card value for blackjack
int get_card_value(Card card){

    switch(card.rank){
        case Two:
        case Three:
        case Four:
        case Five:
        case Six:
        case Seven:
        case Eight:
        case Nine:
        case Ten:
            return card.rank;

        case Jack:
        case Queen:
        case King:
            return 10;

        case Ace:
            return 11;

        default:
            fprintf(stderr, "Card has invalid rank\n");
            exit(EXIT_FAILURE);
    }
}

//Prints the card in readable format
void print_card(Card card){

    const char *suit_names[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    const char *rank_names[] = {"", "", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

    printf("%s of %s\n", rank_names[card.rank], suit_names[card.suit]);
}