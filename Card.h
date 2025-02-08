#ifndef CARD_H
#define CARD_H

#include <string>
#include <QLabel>

class Card {
public:
    Card(const std::string &rank, const std::string &suit);
    int calculateScore() const;
    QLabel* createLabel(QWidget *parent = nullptr, bool isHidden = false) const;

    std::string rank;
    std::string suit;
};

#endif // CARD_H