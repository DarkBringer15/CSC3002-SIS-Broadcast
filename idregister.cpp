#include "idregister.h"
#include "ui_idregister.h"
#include "login.h"
#include <QMessageBox>

IDRegister::IDRegister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IDRegister)
{
    ui->setupUi(this);
    ui->label_7->hide();
    ui->label_8->hide();
    QPixmap bkgnd(":/img/Assets/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    Login conn;
    if (!conn.connOpen()) {
        ui->label_3->setText("Failed");
    } else ui->label_3->setText("Connected");
}

IDRegister::~IDRegister()
{
    delete ui;
}
struct Student {
    QString name;
    QString userID;
    QString Pass;
} ;

void IDRegister::on_pushButton_2_clicked()
{
    this->close();
    Login *login = new Login();
    login->show();
}

void IDRegister::on_pushButton_clicked()
{
    Login conn;

        // Open the connection before executing any queries
        if (!conn.connOpen()) {
            qDebug() << "Failed to open database";
            ui->label_5->setText("Database connection failed");
            return;
        }
        Student studreg;
        studreg.name = ui->txt_Name->text();
        studreg.userID = ui->txt_ID->text();
        if (studreg.userID.length() < 8) {
            ui->label_7->setText("8 char atleast");
            ui->label_7->setStyleSheet("color: red; ");
            ui->label_7->show();
        }
        studreg.Pass = ui->txt_Password->text();
        if (studreg.Pass.length() < 8) {
            ui->label_8->setText("8 char atleast");
            ui->label_8->setStyleSheet("color: red; ");
            ui->label_8->show();
        }
        if (studreg.userID.length() < 8|| studreg.Pass.length() < 8) {
            return;
        }



        QSqlQuery queries;

        // Check if the user ID already exists
        queries.prepare("SELECT * FROM Student WHERE StudentID = :username");
        queries.bindValue(":username", studreg.userID);

        if (!queries.exec()) {
            qDebug() << "Query execution failed: " << queries.lastError();
            conn.connClose();
            return;
        }

        int count = 0;
        while (queries.next()) count++;

        if (count == 0) {
            queries.prepare("INSERT INTO Student (Name, StudentID, Password) VALUES (:name, :userID, :password)");
            queries.bindValue(":name", studreg.name);
            queries.bindValue(":userID", studreg.userID);
            queries.bindValue(":password", studreg.Pass);

            if (queries.exec()) {
                QMessageBox::information(this, tr("Save"), tr("Saved Successfully"));
                conn.connClose();
                this->close();
                Login *login = new Login();
                login->show();
            } else {
                QMessageBox::critical(this, tr("Error"), tr("Failed to save: ") + queries.lastError().text());
            }

        } else {
            ui->label_5->setText("User Exists");
        }

        // Close the database connection
        conn.connClose();
}
