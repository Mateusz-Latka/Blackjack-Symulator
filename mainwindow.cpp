#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "balancewindow.h"
#include "leaderboardwindow.h"
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Blackjack Symulator");
    setWindowIcon(QIcon(":/image/logo.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PlayButton_clicked()
{
    auto *NewGame = new BalanceWindow();
    NewGame->StartingBalance();
    NewGame->show();
    this->hide();
}


void MainWindow::on_H2PButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.blackjackapprenticeship.com/how-to-play-blackjack/"));
}


void MainWindow::on_LeaderButton_clicked()
{
    auto *leaderboard = new LeaderboardWindow();
    leaderboard->show();
    this->hide();
}

