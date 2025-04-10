#include "scoremanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include "../ui/styledmessagebox.h"
#include <QSqlDatabase>

ScoreManager::ScoreManager() = default;

ScoreManager::~ScoreManager() {
    if (db.isOpen()) {
        db.close();
    }
}

bool ScoreManager::initializeDatabase(const QString &dbPath) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        StyledMessageBox::critical(nullptr, "Database Error", "Could not open database: " + db.lastError().text());
        return false;
    }

    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS scores (name TEXT, score INTEGER)")) {
        StyledMessageBox::critical(nullptr, "Database Error", "Could not create table: " + query.lastError().text());
        return false;
    }

    return true;
}

QVector<QPair<QString, int>> ScoreManager::readScores() {
    QVector<QPair<QString, int>> scores;
    QSqlQuery query("SELECT name, score FROM scores ORDER BY score DESC");

    while (query.next()) {
        QString name = query.value(0).toString();
        int score = query.value(1).toInt();
        scores.append(qMakePair(name, score));
    }

    return scores;
}

bool ScoreManager::writeScore(const QString &name, int score) {
    QSqlQuery query;
    query.prepare("INSERT INTO scores (name, score) VALUES (:name, :score)");
    query.bindValue(":name", name);
    query.bindValue(":score", score);

    if (!query.exec()) {
        StyledMessageBox::critical(nullptr, "Database Error", "Could not insert score: " + query.lastError().text());
        return false;
    }

    return true;
}