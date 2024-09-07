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
    Jack = 10,
    Queen = 10,
    King = 10,
    Ace = 11,
} Rank;

typedef struct {
    Suit suit;
    Rank rank;
} Card;