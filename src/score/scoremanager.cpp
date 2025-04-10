#include "scoremanager.h"
#include <QFile>
#include "../ui/styledmessagebox.h"

QVector<QPair<QString, int>> ScoreManager::readScores(const QString &filePath) {
    QVector<QPair<QString, int>> scores;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        StyledMessageBox::critical(nullptr, "Error", "Could not open " + filePath);
        return scores;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        if (parts.size() == 2) {
            QString name = parts[0];
            int score = parts[1].toInt();
            scores.append(qMakePair(name, score));
        }
    }
    file.close();
    return scores;
}

bool ScoreManager::writeScore(const QString &filePath, const QString &name, int score) {
    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        StyledMessageBox::critical(nullptr, "Error", "Could not open file to save score.");
        return false;
    }

    QTextStream out(&file);
    out << name << " " << score << "\n";
    file.close();
    return true;
}