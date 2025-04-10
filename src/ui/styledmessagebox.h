#ifndef STYLEDMESSAGEBOX_H
#define STYLEDMESSAGEBOX_H

#include <QMessageBox>
#include <QWidget>
#include <QPixmap>

class StyledMessageBox : public QMessageBox {
    Q_OBJECT

public:
    explicit StyledMessageBox(QWidget *parent = nullptr);

    static StyledMessageBox* customCritical(QWidget *parent, const QString &title, const QString &text,
                                                     StandardButtons buttons = Ok, StandardButton defaultButton = NoButton);

    static StyledMessageBox* success(QWidget *parent, const QString &title, const QString &text,
                                                   StandardButtons buttons = Ok, StandardButton defaultButton = NoButton);
};

#endif // STYLEDMESSAGEBOX_H
