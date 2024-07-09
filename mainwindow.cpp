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
    ui->labelRonda->setText(QString::fromStdString("Ronda " + std::to_string(ronda)));
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
    // Esto deberia estar en Iniciar o algo asi
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


void MainWindow::on_pushButton_2_clicked()
{
    InitDialog initDialog;
    initDialog.setModal(true);

    initDialog.exec();
    Cartuchos *cartuchos = initDialog.getCartuchos();
    setCartuchos(cartuchos);
    updateVista();
}


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
        std::string personaDispara = "Dealer";
        realizarDisparo(disparo, personaRecibe, personaDispara);
        updateVista();

    }
}

void MainWindow::realizarDisparo(bool disparo,
                                 std::string personaRecibe,
                                 std::string personaDispara) {
    Cartuchos *cartuchos = getCartuchos();
    bool nextRound = realizarDescuentos(
        ronda, disparo, personaRecibe, personaDispara, cartuchos, player, dealer);
    if (nextRound) {
        winRound->exec();
        cartuchos->reset();
    }
}
// Actualiza el valor mostrado por los widgets
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

void MainWindow::updateRonda() {
    valoresRonda(getRonda(), &player, &dealer);
    winRound->close();
}

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


