#include "Card.h"
#include <QString>
#include <QPixmap>

Card::Card(const std::string &rank, const std::string &suit) : rank(rank), suit(suit) {}

int Card::calculateScore() const {
    if (rank == "Ace") return 11;
    if (rank == "King" || rank == "Queen" || rank == "Jack") return 10;
    try {
        return std::stoi(rank);
    } catch (const std::invalid_argument &e) {
        return 0;
    }
}

QLabel* Card::createLabel(QWidget *parent, bool isHidden) const {
    QLabel *label = new QLabel(parent);
    QPixmap pixmap;
    if (isHidden) {
        pixmap = QPixmap(":/cards/back_of_card.png");
    } else {
        QString imagePath = QString(":/cards/%1_of_%2.png").arg(QString::fromStdString(rank).toLower()).arg(QString::fromStdString(suit).toLower());
        pixmap = QPixmap(imagePath);
    }
    label->setPixmap(pixmap);
    label->setFixedSize(72*1.5, 96*1.5);
    label->setAlignment(Qt::AlignCenter);
    label->setScaledContents(true);
    return label;
}