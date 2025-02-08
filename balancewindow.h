#ifndef BALANCEWINDOW_H
#define BALANCEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BalanceWindow; }
QT_END_NAMESPACE

class BalanceWindow : public QMainWindow
{
    Q_OBJECT

public:
    BalanceWindow(QWidget *parent = nullptr);
    ~BalanceWindow();

    void StartingBalance();
    void setBet(int bet);
    int getBet() const;

    private slots:
        void on_StartBlackjackButton_clicked();
    void handleGameOver(int gameResult);

private:
    Ui::BalanceWindow *ui;
    int balance;
    int totalWinnings;
};

#endif // BALANCEWINDOW_H