#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <cmath>
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

std::string floatToString(float value, int precision) ;

#endif // UTILS_H
