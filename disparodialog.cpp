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

void DisparoDialog::setPersonaElegida(std::string persona) {
    ui->label_jugador->setText(QString::fromStdString(persona));
}
//---------------------

// ------Getters-------
bool DisparoDialog::getDisparo() {
    return this->disparo;
}
//---------------------

void DisparoDialog::on_pushButtonSi_clicked()
{
    setDisparo(true);
    this->close();
}


void DisparoDialog::on_pushButtonNo_clicked()
{
    setDisparo(false);
    this->close();
}

