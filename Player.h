#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Deck.h"

class Player {
public:
    Hand hand;
    int score;

    Player();
    void drawCard(Deck &deck);
};

#endif // PLAYER_H