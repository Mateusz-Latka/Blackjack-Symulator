#pragma once
#include <QSqlDatabase>
#include <QVector>
#include <QPair>
#include <QString>

class ScoreManager {
public:
    ScoreManager();
    ~ScoreManager();

    bool initializeDatabase(const QString &dbPath);
    static QVector<QPair<QString, int>> readScores();
    static bool writeScore(const QString &name, int score);

private:
    QSqlDatabase db;
};