#include "winround.h"
#include "ui_winround.h"

WinRound::WinRound(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WinRound)
{
    ui->setupUi(this);
    //connect(ui->pushButton, &QPushButton::clicked, this, &WinRound::on_pushButton_clicked);
}

WinRound::~WinRound()
{
    delete ui;
}

void WinRound::on_pushButton_clicked()
{
    emit buttonClicked();

    /*
    valoresRonda(getRonda(), getPlayer(), getDealer());
    this->close();
*/
}
/*
void WinRound::setPlayer(Persona &player) {
    this->player = player;
}

void WinRound::setDealer(Persona &dealer) {
    this->dealer = dealer;
}

void WinRound::setRonda(int ronda) {
    this->ronda = ronda;
}

Persona &WinRound::getPlayer() {
    return this->player;
}

Persona &WinRound::getDealer() {
    return this->dealer;
}

int WinRound::getRonda() {
    return this->ronda;
}
*/
