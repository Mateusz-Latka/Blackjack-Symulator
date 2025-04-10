#include <QApplication>
#include "ui/mainwindow.h"
#include "score/scoremanager.h"
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ScoreManager scoreManager;
    if (!scoreManager.initializeDatabase("scores.db")) {
        qDebug() << "Failed to initialize database.";
        return -1;
    }

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
