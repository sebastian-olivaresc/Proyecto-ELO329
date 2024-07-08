#include "initdialog.h"
#include "ui_initdialog.h"
#include "cartuchos.h"

InitDialog::InitDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InitDialog)
{
    ui->setupUi(this);
}

InitDialog::~InitDialog()
{
    delete ui;
}

Cartuchos *InitDialog::getCartuchos() {
    return this->cartuchos;
}

void InitDialog::setCartuchos(int vacios, int cargados) {
    this->cartuchos = new Cartuchos(vacios, cargados);
}

void InitDialog::on_pushButton_clicked()
{

    int vacios = ui->spinBox->value();
    int cargados = ui->spinBox_2->value();
    setCartuchos(vacios, cargados);
    this->close();
}

