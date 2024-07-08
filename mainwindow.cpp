#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "initdialog.h"
#include "decisiondialog.h"
#include "utils.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


// -----Setters----
void MainWindow::setCartuchos(Cartuchos *cartuchos) {
    this->cartuchos = cartuchos;
}

void MainWindow::setJugadores(Persona *player, Persona *dealer) {
    this->dealer = dealer;
    this->player = player;
    // Esto deberia estar en Iniciar o algo asi
    int vidasDealer = dealer->getVida();
    int vidasPlayer = player->getVida();
    ui->vidasDealer->display(vidasDealer);
    ui->vidasPlayer->display(vidasPlayer);
}
// ----------------

// -----Getters----
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
    ui->spinBox_vacios->setValue(cartuchos->getVacios());
    ui->spinBox_cargados->setValue(cartuchos->getCargados());
}


void MainWindow::on_pushButton_clicked()
{
    DecisionDialog decisionDialog;
    decisionDialog.setModal(true);

    decisionDialog.setPersona(elegirDisparo(cartuchos));
    decisionDialog.setProbabilidad(getCartuchos()->probabilidadVacios());

    decisionDialog.exec();

    // Datos para hacer los descuentos

    bool disparo = decisionDialog.getDisparo();
    std::string persona = decisionDialog.getPersonaElegida();

    Cartuchos *cartuchos = getCartuchos();
    realizarDescuentos(disparo, persona, cartuchos, player, dealer, 1);
    ui->spinBox_vacios->setValue(cartuchos->getVacios());
    ui->spinBox_cargados->setValue(cartuchos->getCargados());
    ui->vidasDealer->display(dealer->getVida());
    ui->vidasPlayer->display(player->getVida());
}

