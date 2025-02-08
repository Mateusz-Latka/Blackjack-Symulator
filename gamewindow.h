#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

namespace Ui {
    class gamewindow;
}

class gamewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit gamewindow(int bet, QWidget *parent = nullptr);
    ~gamewindow();

signals:
    void gameOver(int result);

private:
    Ui::gamewindow *ui;
    Deck deck;
    Player player;
    Dealer dealer;
    int bet;

    void initializeGame();
    void updateUI();
    void clearLayout(QLayout *layout);
    QLabel* createCardLabel(const Card &card, bool isHidden = false);

private slots:
    void on_HitButton_clicked();
    void on_StandButton_clicked();
};

#endif // GAMEWINDOW_H