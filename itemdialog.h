#ifndef ITEMDIALOG_H
#define ITEMDIALOG_H

#include <QDialog>

#include "persona.h"

namespace Ui {
class ItemDialog;
}

class ItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ItemDialog(QWidget *parent = nullptr);
    ~ItemDialog();

    void setPlayer(Persona *player);
    void setDealer(Persona *dealer);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ItemDialog *ui;
    Persona *player;
    Persona *dealer;
};

#endif // ITEMDIALOG_H
