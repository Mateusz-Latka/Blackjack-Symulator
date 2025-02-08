//
// Created by Mateusz on 13.01.2025.
//

#ifndef LEADERBOARDWINDOW_H
#define LEADERBOARDWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class LeaderboardWindow; }
QT_END_NAMESPACE

class LeaderboardWindow : public QMainWindow {
Q_OBJECT

public:
    explicit LeaderboardWindow(QWidget *parent = nullptr);
    ~LeaderboardWindow() override;
public slots:
    void on_backButton_clicked();
private:
    Ui::LeaderboardWindow *ui;
};


#endif //LEADERBOARDWINDOW_H
