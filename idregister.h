#ifndef IDREGISTER_H
#define IDREGISTER_H

#include <QDialog>

namespace Ui {
class IDRegister;
}

class IDRegister : public QDialog
{
    Q_OBJECT

public:
    explicit IDRegister(QWidget *parent = nullptr);
    ~IDRegister();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::IDRegister *ui;
};

#endif // IDREGISTER_H
