#include "disparodialog.h"
#include "ui_disparodialog.h"

DisparoDialog::DisparoDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DisparoDialog)
{
    ui->setupUi(this);
}

DisparoDialog::~DisparoDialog()
{
    delete ui;
}

// ------Setters-------
void DisparoDialog::setDisparo(bool disparo) {
    this->disparo = disparo;
}

// Titulo: setPersonaElegida 
// Parametros: std::string persona 
// Output: void
// Funcion: Esta funcion cambia la el label de la persona en la ventana 
void DisparoDialog::setPersonaElegida(std::string persona) {
    ui->label_jugador->setText(QString::fromStdString(persona));
}
//---------------------

// ------Getters-------
bool DisparoDialog::getDisparo() {
    return this->disparo;
}
//---------------------


//---------Botones----------

// Titulo: on_pushButtonSi_clicked
// Parametros: Ninguno
// Output: void
// Funcion: Esta funcion guarda el disparo como true(vacio) 
void DisparoDialog::on_pushButtonSi_clicked()
{
    setDisparo(true);
    this->close();
}


// Titulo: on_pushButtonNo_clicked
// Parametros: Ninguno
// Output: void
// Funcion: Esta funcion guarda el disparo como false(cargado) 
void DisparoDialog::on_pushButtonNo_clicked()
{
    setDisparo(false);
    this->close();
}
//--------------------------
