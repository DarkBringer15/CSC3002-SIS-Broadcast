#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/img/Assets/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    QPixmap logo (":/img/Assets/Emblem_of_CU.png");

    ui->label_7->setPixmap(logo);
    if (!connOpen()) {
        ui->label->setText("failed to connect");
    } else {
        ui->label->setText("Connected");
    }
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{




    username = ui->lineEdit_username->text();
    Password = ui->lineEdit_Password->text();


    if (!connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    QSqlQuery queries;
    queries.prepare("SELECT * FROM Student WHERE StudentID=:username AND Password=:password");
    queries.bindValue(":username", username);
    queries.bindValue(":password", Password);

    if (!queries.exec()) {
        qDebug() << "Query execution failed: " << queries.lastError();
        return;
    }

    int count = 0;
    while (queries.next()) {
        count++;
    }

    if (count == 1) {
        ui->label_4->setText("Success");
        this->hide();
        homewindow homewindow(&username, &Password, this);
        homewindow.setModal(true);
        homewindow.exec();

    } else {
        ui->label_4->setText("Failed");
    }
}

void Login::on_pushButton_2_clicked()
{
    this->hide();
    IDRegister idregister;
    idregister.setModal(true);
    idregister.exec();
}
