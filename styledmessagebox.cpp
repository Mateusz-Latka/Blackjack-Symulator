#include "styledmessagebox.h"
#include <QDebug>

StyledMessageBox::StyledMessageBox(QWidget *parent)
    : QMessageBox(parent) {

    this->setWindowIcon(QIcon(":/image/logo.png"));
    this->setWindowTitle("Blackjack Symulator");

    this->setStyleSheet(
        "QMessageBox {"
        "    background-color: none;"
        "}"
        "QMessageBox QPushButton {"
        "    background-color: #FFD700;"
        "    color: black;"
        "    border: 2px solid #B8860B;"
        "    padding: 10px 20px;"
        "    text-align: center;"
        "    text-decoration: none;"
        "    display: inline-block;"
        "    font-size: 16px;"
        "    font-family: 'Arial';"
        "    margin: 4px 2px;"
        "    transition-duration: 0.4s;"
        "    cursor: pointer;"
        "}"
        "QMessageBox QPushButton:hover {"
        "    background-color: #B8860B;"
        "    color: white;"
        "}"
        "QMessageBox QLabel {"
        "    color: white;"
        "    font-size: 14px;"
        "}"
    );
}

StyledMessageBox* StyledMessageBox::customCritical(QWidget *parent, const QString &title, const QString &text,
                                                           StandardButtons buttons, StandardButton defaultButton) {
    StyledMessageBox *msgBox = new StyledMessageBox(parent);

    msgBox->setText(text);
    msgBox->setWindowTitle(title);

    msgBox->setIcon(QMessageBox::Critical);

    msgBox->setStandardButtons(buttons);
    msgBox->setDefaultButton(defaultButton);

    msgBox->exec();
    return msgBox;
}

StyledMessageBox* StyledMessageBox::success(QWidget *parent, const QString &title, const QString &text,
                                                           StandardButtons buttons, StandardButton defaultButton) {
    StyledMessageBox *msgBox = new StyledMessageBox(parent);

    msgBox->setText(text);
    msgBox->setWindowTitle(title);


    QPixmap pixmap(":/image/success.png");
    QPixmap scaledPixmap = pixmap.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    msgBox->setIconPixmap(scaledPixmap);

    msgBox->setStandardButtons(buttons);
    msgBox->setDefaultButton(defaultButton);

    msgBox->exec();
    return msgBox;
}

