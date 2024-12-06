#ifndef BROADCAST_H
#define BROADCAST_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class broadcast;
}

class broadcast : public QDialog
{
    Q_OBJECT

public:
    explicit broadcast(QWidget *parent = nullptr);
    ~broadcast();

private slots:
    void on_pushButton_clicked();
    void on_uploadImageButton_clicked();
    void updateDisplayLabel();
    void adjustFontSize(QLabel *label, const QString &text, int fontSize);

private:
    Ui::broadcast *ui;
};

#endif // BROADCAST_H

