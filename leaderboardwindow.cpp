#include "leaderboardwindow.h"
#include "ui_LeaderboardWindow.h"
#include "scoremanager.h"
#include <algorithm>
#include "mainWindow.h"
#include <QDir>

LeaderboardWindow::LeaderboardWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::LeaderboardWindow) {
    ui->setupUi(this);
    setWindowTitle("Blackjack Symulator - Leaderboard");
    setWindowIcon(QIcon(":/image/logo.png"));
    ui->leaderboardListWidget->setStyleSheet("font-size: 30px;");
    connect(ui->ToMainLobbyButton, &QPushButton::clicked, this, &LeaderboardWindow::on_backButton_clicked);

    QString filePath = QDir::currentPath() + "/Leaderboard/data.txt";
    QVector<QPair<QString, int>> scores = ScoreManager::readScores(filePath);

    std::sort(scores.begin(), scores.end(), [](const QPair<QString, int> &a, const QPair<QString, int> &b) {
        return a.second > b.second;
    });

    int position = 1;
    QString positionString;
    for (const auto &entry : scores) {
        if(position == 1){
            positionString = "🥇";
        }
        else if(position == 2){
            positionString = "🥈";
        }
        else if(position == 3) {
            positionString = "🥉";
        }
        else {
            positionString = " " + QString::number(position) + ". ";
        }
        ui->leaderboardListWidget->addItem(positionString + entry.first + ": " + QString::number(entry.second));
        position++;
    }
}

LeaderboardWindow::~LeaderboardWindow() {
    delete ui;
}

void LeaderboardWindow::on_backButton_clicked() {
    auto *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}