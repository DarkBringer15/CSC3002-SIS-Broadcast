#include "announcement.h"
#include "ui_announcement.h"
#include "homewindow.h"
#include <QMessageBox>
Announcement::Announcement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Announcement)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/img/Assets/Announc_back.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

}

Announcement::~Announcement()
{
    delete ui;
}

void Announcement::on_pushButton_2_clicked()
{
    QSqlDatabase announcementdb;
    announcementdb = QSqlDatabase::addDatabase("QSQLITE");
    announcementdb.setDatabaseName("C:/Users/Nick/Downloads/CSC3002-SIS-Main/CSC3002-SIS-main/CSC3002-SIS-main/Database/announcementdb.db");
    if (!announcementdb.open()) {
        qDebug ()<< ("announcement failed to connect");
        return;
    } else {
        qDebug() << ("Announcement Connected");
    }
    QString title;
    QString description;
    title = ui->lineEdit->text();
    description = ui->textEdit->toPlainText();
    QSqlQuery queries;
    queries.prepare("INSERT INTO Announcements (Title, Description) VALUES (:title, :description)");
    queries.bindValue(":title", title);
    queries.bindValue(":description", description);
    if (queries.exec()) {
        QMessageBox::information(this, tr("Save"), tr("Saved Successfully"));
    } else {
        QMessageBox::critical(this, tr("Error"), tr("Failed to save: ") + queries.lastError().text());
    }





}

void Announcement::on_pushButton_clicked()
{
    this->close();
}
