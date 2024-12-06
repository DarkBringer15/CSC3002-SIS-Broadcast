#include "broadcast.h"
#include "ui_broadcast.h"
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QFontMetrics>

broadcast::broadcast(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::broadcast)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/img/Assets/#68246a.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    connect(ui->uploadImageButton, &QPushButton::clicked, this, &broadcast::on_uploadImageButton_clicked);
    connect(ui->title, &QLineEdit::textChanged, this, &broadcast::updateDisplayLabel);
}

broadcast::~broadcast()
{
    delete ui;
}

void broadcast::on_uploadImageButton_clicked()
{
    // Open a file dialog to select an image
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));

    if (!fileName.isEmpty()) {
        QPixmap image(fileName);

        if (!image.isNull()) {
            ui->image->setPixmap(image.scaled(ui->image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            // if Error
            QMessageBox::warning(this, tr("Error"), tr("Could not load the image."));
        }
    }
}

void broadcast::on_pushButton_clicked()
{
    this->close();
}

void broadcast::updateDisplayLabel()
{
    QString titleText = ui->title->text().left(60);
    ui->displayLabel->setText(titleText);
    adjustFontSize(ui->displayLabel, titleText, 24);
}

void broadcast::adjustFontSize(QLabel *label, const QString &text, int fontSize)
{
    // Set the font size
    QFont font = label->font();
    font.setPointSize(fontSize);
    label->setFont(font);
    QFontMetrics metrics(font);
    int textWidth = metrics.horizontalAdvance(text);

    if (textWidth > label->width() && fontSize > 1) {
        adjustFontSize(label, text, fontSize - 1);
    }
}
