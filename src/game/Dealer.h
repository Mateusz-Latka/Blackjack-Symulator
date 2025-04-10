#ifndef DEALER_H
#define DEALER_H

#include "Player.h"

class Dealer : public Player {
public:
    bool isCardHidden;
    Card hiddenCard;

    Dealer();
    void revealHiddenCard();
};

#endif // DEALER_H