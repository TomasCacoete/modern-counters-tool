#ifndef CARD_H
#define CARD_H

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


int get_card_value(Card card);
void print_card(Card card);

#endif