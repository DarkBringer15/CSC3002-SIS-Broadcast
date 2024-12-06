#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "idregister.h"
#include "homewindow.h"
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase mydb;
    bool connOpen() {

        mydb = QSqlDatabase::addDatabase("QSQLITE");
        QString temp = QCoreApplication::applicationDirPath();
        mydb.setDatabaseName("C:/Users/Nick/Downloads/CSC3002-SIS-Main/CSC3002-SIS-main/CSC3002-SIS-main/Database/mydb.db");
        qDebug() << temp;
        if (!mydb.open()) {
            qDebug ()<< ("failed to connect");
            return false;
        } else {
            qDebug() << ("Connected");
            return true;
        }
    }
    void connClose() {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    QString username;
    QString Password;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;

};

#endif // LOGIN_H
