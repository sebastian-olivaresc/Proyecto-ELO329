#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "initdialog.h"
#include "decisiondialog.h"
#include "utils.h"
#include "winround.h"
#include "decisiondealerdialog.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , winRound(new WinRound)
{
    ui->setupUi(this);

    // Escribe numero de ronda al inicio
    ui->labelRonda->setText(QString::fromStdString("Ronda " + std::to_string(ronda)));

    // Conecta signal de WinRound y slot the MainWindow
    // Presionar el boton en WinRound avanza a la siguiente ronda
    // en MainWindow
    connect(winRound, &WinRound::buttonClicked, this, &MainWindow::updateRonda);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete winRound;
}


// -----Setters----
void MainWindow::setRonda(int ronda) {
    this->ronda = ronda;
}

void MainWindow::setCartuchos(Cartuchos *cartuchos) {
    this->cartuchos = cartuchos;
}

void MainWindow::setJugadores(Persona *player, Persona *dealer) {
    this->dealer = dealer;
    this->player = player;
    updateVista();
}
// ----------------

// -----Getters----
int MainWindow::getRonda() {
    return this->ronda;
}
Cartuchos *MainWindow::getCartuchos() {
    return this->cartuchos;
}
// ----------------


//---------Botones----------

// Titulo: on_pushButton_2_clicked
// Parametros: Ninguno
// Output: void
// Funcion: Esta funcion muestra la ventana initDialog para ingresar
// la cantidad de cartuchos al inicio de una ronda. 
void MainWindow::on_pushButton_2_clicked()
{
    InitDialog initDialog;
    initDialog.setModal(true);
    initDialog.setRonda(getRonda());

    initDialog.exec();

    Cartuchos *cartuchos = initDialog.getCartuchos();
    setCartuchos(cartuchos);
    updateVista();
}


// Titulo: on_pushButtonAccionPlayer_clicked
// Parametros: Ninguno
// Output: void
// Funcion: Esta funcion muestra la ventana decisionDialog y prepara
// los datos para que Player realice un disparo
void MainWindow::on_pushButtonAccionPlayer_clicked()
{
    DecisionDialog decisionDialog;
    decisionDialog.setModal(true);

    if (cartuchos != nullptr) {
        decisionDialog.setPersona(elegirDisparo(cartuchos));
        decisionDialog.setProbabilidad(getCartuchos()->probabilidadVacios());

        decisionDialog.exec();

        // Datos para hacer los descuento
        bool disparo = decisionDialog.getDisparo();
        std::string personaRecibe = decisionDialog.getPersonaElegida();
        std::string personaDispara = "Player";
        realizarDisparo(disparo, personaRecibe, personaDispara);
        updateVista();
    }
}

// Titulo: on_pushButtonAccionDealer_clicked
// Parametros: Ninguno
// Output: void
// Funcion: Esta funcion muestra la ventana decisionDialog y prepara
// los datos para que Dealer realice un disparo
void MainWindow::on_pushButtonAccionDealer_clicked()
{
    DecisionDealerDialog decisionDealerDialog;
    decisionDealerDialog.setModal(true);

    if (cartuchos != nullptr) {
        decisionDealerDialog.exec();

        // Datos para hacer los descuento
        bool disparo = decisionDealerDialog.getDisparo();
        std::string personaRecibe = decisionDealerDialog.getPersonaElegida();
        std::string personaDispara = "Dealer";
        realizarDisparo(disparo, personaRecibe, personaDispara);
        updateVista();

    }
}
//------------------------


// Titulo: realizarDisparo
// Parametros:  bool disparo,
//              std::string personaRecibe,
//              std::string personaDispara
// Output: void
// Funcion: Esta funcion ocupa la funcion realizarDescuentos para efectuar el
// disparo, entregando si el disparo fue vacio o cargado, quien lo dispara y a
// quien. Luego muestra la pantalla de victoria de la ronda si se gana y resetea
// los cartuchos a 0 para la siguiente ronda.
void MainWindow::realizarDisparo(bool disparo,
                                 std::string personaRecibe,
                                 std::string personaDispara) {

    Cartuchos *cartuchos = getCartuchos();
    bool nextRound = realizarDescuentos(ronda, disparo, personaRecibe, 
                                        personaDispara, cartuchos, player, 
                                        dealer);
    if (nextRound) {
        winRound->exec();
        cartuchos->reset();
    }
}

// Titulo: updateVista 
// Parametros: Ninguno
// Output: void
// Funcion: Esta funcion actualiza los valores en los widgets, el numero de
// ronda, los cartuchos y las vidas.
void MainWindow::updateVista() {
    // Update ronda
    ui->labelRonda->setText(QString::fromStdString("Ronda " + std::to_string(ronda)));

    // Update cartuchos
    if (cartuchos != nullptr) {
        ui->lcdVacios->display(cartuchos->getVacios());
        ui->lcdCargados->display(cartuchos->getCargados());
    }

    // Update vidas
    ui->vidasDealer->display(dealer->getVida());
    ui->vidasPlayer->display(player->getVida());
}

// Titulo: updateRonda
// Parametros: Ninguno
// Output: void
// Funcion: Esta funcion es ejecutada al precionar el boton en la
// ventana WinRound usando signal y slots. Se usa la funcion valoresRonda para
// dar los valores de la nueva ronda a los jugadores, finalmente se cierra la
// ventana WinRound.
void MainWindow::updateRonda() {
    valoresRonda(getRonda(), &player, &dealer);
    winRound->close();
}

