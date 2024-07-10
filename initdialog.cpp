#include "initdialog.h"
#include "ui_initdialog.h"
#include "cartuchos.h"
#include "itemdialog.h"
#include <iostream>

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


//-----Setters----
void InitDialog::setCartuchos(int vacios, int cargados) {
    this->cartuchos = new Cartuchos(vacios, cargados);
}

void InitDialog::setRonda(int ronda) {
    this->ronda = ronda;
}
//----------------

//-----Getters----
Cartuchos *InitDialog::getCartuchos() {
    return this->cartuchos;
}

int InitDialog::getRonda() {
    return this->ronda;
}
//----------------



//------Botones------
// Titulo: on_pushButton_clicked
// Parametros: Ninguno
// Output: void
// Funcion: Esta funcion guarda los valores de los spinBox de los cartuchos 
void InitDialog::on_pushButton_clicked()
{
    int vacios = ui->spinBox->value();
    int cargados = ui->spinBox_2->value();
    setCartuchos(vacios, cargados);

    if (getRonda() > 1) {
        ItemDialog itemDialog;
        itemDialog.setModal(true);
        itemDialog.exec();
    }

    this->close();
}
//-------------------

