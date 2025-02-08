#include "Hand.h"

void Hand::addCard(const Card &card) {
    cards.push_back(card);
}

int Hand::calculateScore() const {
    int score = 0;
    int aces = 0;
    for (const auto &card : cards) {
        if (card.rank == "Ace") {
            score += 11;
            aces++;
        } else if (card.rank == "Jack" || card.rank == "Queen" || card.rank == "King") {
            score += 10;
        } else {
            score += std::stoi(card.rank);
        }
    }
    while (score > 21 && aces > 0) {
        score -= 10;
        aces--;
    }
    return score;
}