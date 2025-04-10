#include "Deck.h"
#include <algorithm>
#include <random>
#include <stdexcept>

Deck::Deck() {
    initializeDeck();
}

void Deck::initializeDeck() {
    std::vector<std::string> ranks = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    std::vector<std::string> suits = {"Spades", "Hearts", "Clubs", "Diamonds"};
    cards.clear();
    for (const auto &suit : suits) {
        for (const auto &rank : ranks) {
            cards.push_back({rank, suit});
        }
    }
    std::shuffle(cards.begin(), cards.end(), std::mt19937(std::random_device()()));
}

Card Deck::drawCard() {
    if (cards.empty()) throw std::out_of_range("No more cards in the deck");
    Card card = cards.back();
    cards.pop_back();
    return card;
}