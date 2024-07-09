#include "cigarros.h"

Cigarros::Cigarros(int cantidad, enum Tipos nombre):
    Item(cantidad, nombre){
}

bool Cigarros::usar(Cartuchos &cartuchos, Persona &persona) {
    bool quedan = aumentarCantidad(-1);
    if (quedan) {
        persona.aumentarVida(1);
    }
    return quedan;
}
