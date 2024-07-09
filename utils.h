#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "cartuchos.h"
#include "persona.h"

using namespace std;

string elegirDisparo(Cartuchos *cartuchos);

bool realizarDescuentos(int &ronda,
                        bool disparo,
                        string personaRecibe,
                        string personaDispara,
                        Cartuchos *cartuchos,
                        Persona *player,
                        Persona *dealer);

void valoresRonda(int ronda, Persona **player, Persona **dealer);

#endif // UTILS_H
