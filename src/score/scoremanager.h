// scoremanager.h
#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <QString>
#include <QVector>
#include <QPair>

class ScoreManager {
public:
    static QVector<QPair<QString, int>> readScores(const QString &filePath);
    static bool writeScore(const QString &filePath, const QString &name, int score);
};

#endif // SCOREMANAGER_H