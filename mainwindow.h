#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "winround.h"

#include "cartuchos.h"
#include "persona.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setRonda(int ronda);
    void setCartuchos(Cartuchos *cartuchos);
    void setJugadores(Persona *player, Persona *dealer);

    int getRonda();
    Cartuchos *getCartuchos();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButtonAccionDealer_clicked();
    void on_pushButtonAccionPlayer_clicked();

private:
    Ui::MainWindow *ui;
    int ronda = 1;
    Cartuchos *cartuchos = nullptr;
    Persona *player = nullptr;
    Persona *dealer = nullptr;
    void updateVista();
    void updateRonda();
    void realizarDisparo(bool disparo, std::string personaRecibe, std::string personaDispara);


    WinRound *winRound;

};
#endif // MAINWINDOW_H
