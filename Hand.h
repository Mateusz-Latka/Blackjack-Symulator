#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
public:
    std::vector<Card> cards;

    void addCard(const Card &card);
    int calculateScore() const;
};

#endif // HAND_H