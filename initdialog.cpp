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


//-----Setters----
void InitDialog::setCartuchos(int vacios, int cargados) {
    this->cartuchos = new Cartuchos(vacios, cargados);
}
//----------------

//-----Getters----
Cartuchos *InitDialog::getCartuchos() {
    return this->cartuchos;
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
    this->close();
}
//-------------------

