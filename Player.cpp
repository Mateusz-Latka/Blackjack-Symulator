#include "Player.h"

Player::Player() : score(0) {}

void Player::drawCard(Deck &deck) {
    hand.addCard(deck.drawCard());
    score = hand.calculateScore();
}