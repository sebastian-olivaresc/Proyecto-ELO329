#include "decisiondialog.h"
#include "ui_decisiondialog.h"
#include "disparodialog.h"

#include <string>
#include <cmath>


std::string floatToString(float value, int precision) {
    std::string str = std::to_string(value);
    str = str.substr(0, str.find('.') + precision + 1); // precision total de 2 decimales
    str.erase(str.find_last_not_of('0') + 1, std::string::npos); // Eliminar ceros a la derecha
    if (str.back() == '.') {
        str.pop_back(); // Eliminar el punto si es el último carácter
    }
    return str;
}

DecisionDialog::DecisionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DecisionDialog)
{
    ui->setupUi(this);
}

DecisionDialog::~DecisionDialog()
{
    delete ui;
}

void DecisionDialog::setDisparo(bool disparo) {
    this->disparo = disparo;
}

void DecisionDialog::setPersona(std::string persona) {
    ui->label_persona->setText(QString::fromStdString(persona));
}

void DecisionDialog::setProbabilidad(float prob) {
    std::string value = floatToString(prob, 2); // Aquí usamos la función floatToString con precisión de 2
    ui->label_prob->setText(QString::fromStdString(value));
}

void DecisionDialog::setPersonaElegida(std::string persona) {
    this->personaElegida = persona;
}

std::string DecisionDialog::getPersonaElegida() {
    return this->personaElegida;
}

bool DecisionDialog::getDisparo() {
    return this->disparo;
}

/*
 * Con estas dos funciones se confirma a quien se disparo
 * y se hacen los descuentos en la interfaz principal
*/

void DecisionDialog::on_pushButtonDealer_clicked()
{
    std::string persona = "Dealer";
    this->close();
    DisparoDialog disparoDialog;
    setPersonaElegida(persona);
    disparoDialog.setPersonaElegida(persona);
    disparoDialog.setModal(true);
    disparoDialog.exec();
    setDisparo(disparoDialog.getDisparo());
}


void DecisionDialog::on_pushButtonPlayer_clicked()
{
    std::string persona = "Player";

    this->close();
    DisparoDialog disparoDialog;
    setPersonaElegida(persona);
    disparoDialog.setPersonaElegida(persona);
    disparoDialog.setModal(true);
    disparoDialog.exec();
    setDisparo(disparoDialog.getDisparo());
}

