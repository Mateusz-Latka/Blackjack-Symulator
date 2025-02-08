#include "balancewindow.h"
#include "ui_balancewindow.h"
#include "gamewindow.h"
#include "gamelogic.h"

#include "styledmessagebox.h"

BalanceWindow::BalanceWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BalanceWindow)
    , balance(0)
    , totalWinnings(0)
{
    ui->setupUi(this);
    setWindowTitle("Blackjack Symulator - Set your bet");
    setWindowIcon(QIcon(":/image/logo.png"));
}

BalanceWindow::~BalanceWindow()
{
    delete ui;
}

void BalanceWindow::StartingBalance()
{
    balance = 1000;
    totalWinnings = 0;
    ui->BetSpinBox->setMaximum(balance);
    ui->BalanceLabel->setText("Balance: " + QString::number(balance) + "💵");
    ui->TotalWiningsLabel->setText("Total Winnings: " + QString::number(totalWinnings)+ "💰");
}

void BalanceWindow::handleGameOver(int gameResult) {
    GameLogic::handleGameOver(gameResult, balance, totalWinnings, getBet(), this);
    if (balance == 0) {
        this->close();
        sender()->deleteLater();
        return;
    }

    ui->BalanceLabel->setText("Balance: " + QString::number(balance) + "💵");
    ui->TotalWiningsLabel->setText("Total Winnings: " + QString::number(totalWinnings)+ "💰");
    ui->BetSpinBox->setMaximum(balance);
    this->show();
    sender()->deleteLater();
}

void BalanceWindow::setBet(int bet) {
    if (bet > balance) {
        StyledMessageBox::customCritical(this, "Invalid Bet", "Bet cannot be greater than balance.");
        return;
    }
    balance -= bet;
    ui->BalanceLabel->setText("Balance: " + QString::number(balance));
}

int BalanceWindow::getBet() const {
    return ui->BetSpinBox->value();
}

void BalanceWindow::on_StartBlackjackButton_clicked()
{
    int bet = ui->BetSpinBox->value();

    if(bet == 0){
        StyledMessageBox::customCritical(this, "Invalid Bet", "Bet cannot be 0.");
        return;
    }

    if (bet > balance) {
        StyledMessageBox::customCritical(this, "Invalid Bet", "Bet cannot be greater than balance.");
        return;
    }
    setBet(bet);
    auto *gameWindow = new gamewindow(bet);
    connect(gameWindow, &gamewindow::gameOver, this, &BalanceWindow::handleGameOver);
    gameWindow->show();
    this->close();
}