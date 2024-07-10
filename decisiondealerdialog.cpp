#include "decisiondealerdialog.h"
#include "ui_decisiondealerdialog.h"

#include "disparodialog.h"

DecisionDealerDialog::DecisionDealerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DecisionDealerDialog)
{
    ui->setupUi(this);
}

DecisionDealerDialog::~DecisionDealerDialog()
{
    delete ui;
}


//---------Setters------------
void DecisionDealerDialog::setDisparo(bool disparo) {
    this->disparo = disparo;
}

void DecisionDealerDialog::setPersonaElegida(std::string persona) {
    this->personaElegida = persona;
}
//----------------------------


//---------Getters------------
std::string DecisionDealerDialog::getPersonaElegida() {
    return this->personaElegida;
}

bool DecisionDealerDialog::getDisparo() {
    return this->disparo;
}
//----------------------------



//---------Botones----------

// Titulo: on_pushButtonDealer_clicked
// Parametros: Ninguno
// Output: void
// Funcion: Esta funcion muestra selecciona el disparo de dealer a dealer 
void DecisionDealerDialog::on_pushButtonDealer_clicked()
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



// Titulo: on_pushButtonDealer_clicked
// Parametros: Ninguno
// Output: void
// Funcion: Esta funcion muestra selecciona el disparo de dealer a player
void DecisionDealerDialog::on_pushButtonPlayer_clicked()
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
//-------------------------------

