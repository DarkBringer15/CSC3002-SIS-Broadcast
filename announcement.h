#ifndef ANNOUNCEMENT_H
#define ANNOUNCEMENT_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Announcement;
}

class Announcement : public QDialog
{
    Q_OBJECT

public:
    explicit Announcement(QWidget *parent = nullptr);
    ~Announcement();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Announcement *ui;
};

#endif // ANNOUNCEMENT_H
