#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QWidget>

class GameLogic {
public:
    static void handleGameOver(int gameResult, int &balance, int &totalWinnings, int bet, QWidget *gameWindow);
};

#endif // GAMELOGIC_H