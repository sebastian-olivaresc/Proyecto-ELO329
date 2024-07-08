#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "cartuchos.h"
#include "persona.h"

using namespace std;

string elegirDisparo(Cartuchos *cartuchos);

void realizarDescuentos(bool disparo,
                        string persona,
                        Cartuchos *cartuchos,
                        Persona *player,
                        Persona *dealer,
                        int descuento);

void valoresRonda(int ronda, Persona **player, Persona **dealer);

#endif // UTILS_H
