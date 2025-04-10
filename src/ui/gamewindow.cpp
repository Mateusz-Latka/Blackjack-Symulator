#include "gamewindow.h"
#include "../../cmake-build-debug/Blackjack-Symulator_autogen/include/ui_gamewindow.h"
#include "../game/Card.h"
#include <QMessageBox>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <QTimer>

#include "styledmessagebox.h"

gamewindow::gamewindow(int bet, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gamewindow),
    bet(bet)
{
    ui->setupUi(this);
    setWindowTitle("Blackjack Symulator - Game");
    setWindowIcon(QIcon(":/image/logo.png"));
    ui->PlayerLayout->setAlignment(Qt::AlignLeft);
    ui->DealerLayout->setAlignment(Qt::AlignLeft);
    initializeGame();
}

gamewindow::~gamewindow()
{
    delete ui;
    clearLayout(ui->PlayerLayout);
    clearLayout(ui->DealerLayout);
}

void gamewindow::initializeGame() {
    deck.initializeDeck();
    player.hand.cards.clear();
    dealer.hand.cards.clear();
    player.score = 0;
    dealer.score = 0;
    dealer.isCardHidden = true;

    player.drawCard(deck);
    player.drawCard(deck);
    dealer.drawCard(deck);
    dealer.hiddenCard = deck.drawCard();
    dealer.hand.addCard(dealer.hiddenCard);

    updateUI();

    if (player.score == 21) {
        QTimer::singleShot(2000, this, [this]() {
                StyledMessageBox::success(this, "You Win!", "Player wins with Blackjack!");
                emit gameOver(1);
        });
    }
}

void gamewindow::clearLayout(QLayout *layout) {
    if (!layout) {
        qWarning("Attempted to clear a null layout.");
        return;
    }
    while (QLayoutItem *item = layout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
}

void gamewindow::updateUI() {
    clearLayout(ui->PlayerLayout);
    clearLayout(ui->DealerLayout);

    for (const Card &card : player.hand.cards) {
        ui->PlayerLayout->addWidget(card.createLabel(this));
    }

    for (size_t i = 0; i < dealer.hand.cards.size(); ++i) {
        if (i == 1 && dealer.isCardHidden) {
            ui->DealerLayout->addWidget(dealer.hand.cards[i].createLabel(this, true));
        } else {
            ui->DealerLayout->addWidget(dealer.hand.cards[i].createLabel(this));
        }
    }

    int visibleDealerScore = 0;
    if (dealer.isCardHidden && dealer.hand.cards.size() > 1) {
        visibleDealerScore = dealer.hand.cards[0].calculateScore();
    }

    ui->PScoreLabel->setText(QString::number(player.score));
    ui->DScoreLabel->setText(dealer.isCardHidden ? QString::number(visibleDealerScore) : QString::number(dealer.score));
}

void gamewindow::on_HitButton_clicked() {
    player.drawCard(deck);
    updateUI();

    if (player.score > 21) {
        dealer.revealHiddenCard();
        updateUI();
        StyledMessageBox::customCritical(this, "You Lost!", "Player busts! Dealer wins.");
        emit gameOver(-1);
    } else if (player.score == 21) {
        dealer.revealHiddenCard();
        dealer.hand.calculateScore();
        updateUI();
        StyledMessageBox::success(this, "You Win!", "Player wins with Blackjack!");
        emit gameOver(1);
    }
}

void gamewindow::on_StandButton_clicked() {
    dealer.revealHiddenCard();
    updateUI();

    while (dealer.hand.calculateScore() < 17) {
        dealer.drawCard(deck);
        updateUI();
    }

    if (dealer.hand.calculateScore() > 21) {
        StyledMessageBox::success(this, "You Win!", "Dealer busts! Player wins.");
        emit gameOver(1);
    } else if (dealer.hand.calculateScore() > player.hand.calculateScore()) {
        StyledMessageBox::customCritical(this, "You Lost!", "Dealer wins.");
        emit gameOver(-1);
    } else if (dealer.hand.calculateScore() < player.hand.calculateScore()) {
        StyledMessageBox::success(this, "You Win!", "Player wins.");
        emit gameOver(1);
    } else {
        StyledMessageBox::information(this, "Push!", "It's a tie.");
        emit gameOver(0);
    }
}