#include "winround.h"
#include "ui_winround.h"

WinRound::WinRound(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WinRound)
{
    ui->setupUi(this);
}

WinRound::~WinRound()
{
    delete ui;
}

//---------Botones----------

// Titulo: on_pushButton_clicked
// Parametros: Ninguno
// Output: void
// Funcion: Esta funcion muestra la ventana manda una singal a mainWindow para
// ejecutar una funcion en aquella ventana.
void WinRound::on_pushButton_clicked()
{
    emit buttonClicked();

}
//--------------------------
