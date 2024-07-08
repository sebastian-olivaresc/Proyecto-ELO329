#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    void setCartuchos(Cartuchos *cartuchos);
    void setJugadores(Persona *player, Persona *dealer);

    Cartuchos *getCartuchos();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Cartuchos *cartuchos = nullptr;
    Persona *player;
    Persona *dealer;

};
#endif // MAINWINDOW_H
