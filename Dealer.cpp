#include "Dealer.h"

Dealer::Dealer() : isCardHidden(true), hiddenCard("Ace", "Spades") {}

void Dealer::revealHiddenCard() {
    if (isCardHidden) {
        score += hiddenCard.calculateScore();
        isCardHidden = false;
    }
}