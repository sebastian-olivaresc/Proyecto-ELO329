#ifndef INITDIALOG_H
#define INITDIALOG_H

#include <QDialog>
#include "cartuchos.h"

namespace Ui {
class InitDialog;
}

class InitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InitDialog(QWidget *parent = nullptr);
    ~InitDialog();
    void setCartuchos(int vacios, int cargados);
    Cartuchos *getCartuchos();

private slots:
    void on_pushButton_clicked();


private:
    Ui::InitDialog *ui;
    Cartuchos *cartuchos;
};

#endif // INITDIALOG_H
