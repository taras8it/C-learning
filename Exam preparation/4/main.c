#include <stdio.h>
#include <string.h>


typedef enum {
    SPADES,
    HEARTS,
    CLUBS,
    DIAMONDS
} Suit;

typedef enum {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
} Number;

typedef struct {
    Suit suit;
    Number number;
} Card;


char * suit_to_string(Suit suit) {
    switch (suit) {
        case SPADES:
            return "spades";
        case HEARTS:
            return "hearts";
        case CLUBS:
            return "clubs";
        case DIAMONDS:
            return "diamonds";
        default:
            return "Unknown";
    }
}

char * number_to_string(Number number) {
    switch (number) {
        case TWO:
            return "two";
        case THREE:
            return "three";
        case FOUR:
            return "four";
        case FIVE:
            return "five";
        case SIX:
            return "six";
        case SEVEN:
            return "seven";
        case EIGHT:
            return "eight";
        case NINE:
            return "nine";
        case TEN:
            return "ten";
        case JACK:
            return "jack";
        case QUEEN:
            return "queen";
        case KING:
            return "king";
        case ACE:
            return "ace";
        default:
            return "Unknown";
    }
}

void print_card(Card card) {
    char suit[9], number[6];
    strcpy(suit, suit_to_string(card.suit));
    strcpy(number, number_to_string(card.number));

    printf("The card is %s of %s", number, suit);
}


int main() {
    Card card = {DIAMONDS, QUEEN};

    print_card(card);
    return 0;
}
