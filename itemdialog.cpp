#include "itemdialog.h"
#include "ui_itemdialog.h"

#include "item.h"
#include "sierra.h"
#include "lupa.h"
#include "cerveza.h"
#include "cigarros.h"
#include "esposas.h"

ItemDialog::ItemDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ItemDialog)
{
    ui->setupUi(this);
}

ItemDialog::~ItemDialog()
{
    delete ui;
}

//----------Setters--------
void ItemDialog::setPlayer(Persona *player) {
    this->player = player;
}

void ItemDialog::setDealer(Persona *dealer) {
    this->dealer = dealer;
}
//-------------------------

//-----------Botones-----------

// Titulo: on_pushButton_clicked
// Parametros: Ninguno
// Output: void
// Funcion: Esta funcion crea los items para dealer y player
void ItemDialog::on_pushButton_clicked()
{
    Item *dealerCerveza = new Cerveza(ui->spinBoxCervezaDealer->value(), CERVEZA);
    Item *dealerSierra = new Sierra(ui->spinBoxSierraDealer->value(), SIERRA);
    Item *dealerCigarros = new Cigarros(ui->spinBoxCigarrosDealer->value(), CIGARROS);
    Item *dealerEsposas = new Esposas(ui->spinBoxEsposasDealer->value(), ESPOSAS);
    Item *dealerLupa = new Lupa(ui->spinBoxLupaDealer->value(), LUPA);

    Item *playerCerveza = new Cerveza(ui->spinBoxCervezaPlayer->value(), CERVEZA);
    Item *playerSierra = new Sierra(ui->spinBoxSierraPlayer->value(), SIERRA);
    Item *playerCigarros = new Cigarros(ui->spinBoxCigarrosPlayer->value(), CIGARROS);
    Item *playerEsposas = new Esposas(ui->spinBoxEsposasPlayer->value(), ESPOSAS);
    Item *playerLupa = new Lupa(ui->spinBoxLupaPlayer->value(), LUPA);

    Inventario *dealerInventario = dealer->getInventario();
    dealerInventario->addItem(dealerCerveza);
    dealerInventario->addItem(dealerSierra);
    dealerInventario->addItem(dealerCigarros);
    dealerInventario->addItem(dealerEsposas);
    dealerInventario->addItem(dealerLupa);

    Inventario *playerInventario = player->getInventario();
    playerInventario->addItem(playerCerveza);
    playerInventario->addItem(playerSierra);
    playerInventario->addItem(playerCigarros);
    playerInventario->addItem(playerEsposas);
    playerInventario->addItem(playerLupa);

    this->close();


}
//------------------------------
