#include "gamelogic.h"
#include <QInputDialog>
#include "../score/scoremanager.h"
#include "../ui/mainwindow.h"
#include "../ui/styledmessagebox.h"

void GameLogic::handleGameOver(int gameResult, int &balance, int &totalWinnings, int bet, QWidget *gameWindow) {
    if (gameResult == 1) {
        balance += bet * 2;
        totalWinnings += bet;
    } else if (gameResult == 0) {
        balance += bet;
    }

    if (balance == 0) {
        StyledMessageBox::StandardButton reply;
        reply = StyledMessageBox::question(gameWindow, "Game Over", "You have run out of points. Do you want to save your score?", StyledMessageBox::Yes | StyledMessageBox::No);
        if (reply == StyledMessageBox::Yes) {
            bool ok;
            QString playerName;
            do {
                playerName = QInputDialog::getText(gameWindow, "Save Score", "Enter your name:", QLineEdit::Normal, "", &ok);
                if (!ok) {
                    StyledMessageBox::customCritical(gameWindow, "Error", "Score not saved.");
                    break;
                }
                if (playerName.isEmpty()) {
                    StyledMessageBox::customCritical(gameWindow, "Error", "Name cannot be empty.");
                }
            } while (playerName.isEmpty());

            if (ok && !playerName.isEmpty()) {
                ScoreManager scoreManager;
                if (!scoreManager.writeScore(playerName, totalWinnings)) {
                    StyledMessageBox::customCritical(gameWindow, "Error", "Failed to save score to the database.");
                }
            }
        }
        StyledMessageBox::information(gameWindow, "Game Over", "Returning to the main menu.");

        auto *mainWindow = new MainWindow();
        gameWindow->close();
        mainWindow->show();
    }
}
