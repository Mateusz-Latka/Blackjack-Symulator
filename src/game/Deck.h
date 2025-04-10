#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
public:
    std::vector<Card> cards;

    Deck();
    void initializeDeck();
    Card drawCard();
};

#endif // DECK_H