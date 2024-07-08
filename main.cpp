#include "mainwindow.h"

#include <QApplication>
#include "persona.h"
#include "utils.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Persona *player = nullptr;
    Persona *dealer = nullptr;

    valoresRonda(1, &player, &dealer);
    std::cout << player->getVida();
    w.setJugadores(player, dealer);
    w.show();

    return a.exec();
}
