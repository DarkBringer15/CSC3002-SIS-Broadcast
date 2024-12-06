#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QtSql>
#include <QIcon>
#include <QFileInfo>

namespace Ui {
    class homewindow;
}

class homewindow : public QDialog
{
    Q_OBJECT

public:
    int currentrowindex = 0;
    int totalrow = 0;
    QSqlDatabase announcementdb;
    bool connOpen() {

        announcementdb = QSqlDatabase::addDatabase("QSQLITE");
        announcementdb.setDatabaseName("C:/Users/Nick/Downloads/CSC3002-SIS-Main/CSC3002-SIS-main/CSC3002-SIS-main/Database/announcementdb.db");
        if (!announcementdb.open()) {
            qDebug ()<< ("announcement failed to connect");
            return false;
        } else {
            qDebug() << ("Announcement Connected");
            return true;
        }
    }
    void connClose() {
        announcementdb.close();
        announcementdb.removeDatabase(QSqlDatabase::defaultConnection);
    }

public:
    explicit homewindow(QString *username, QString *Password, QWidget *parent = nullptr);
    ~homewindow();


private slots:
    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_6_clicked(bool checked);

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::homewindow *ui;
    bool checked = false;
    bool checked1 = false;
    QString *username;
    QString *Password;
};

#endif // HOMEWINDOW_H
