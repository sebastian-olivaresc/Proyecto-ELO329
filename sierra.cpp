#include "sierra.h"

Sierra::Sierra(int cantidad, enum Tipos nombre):
    Item(cantidad, nombre){
}

bool Sierra::usar(Cartuchos &cartuchos, Persona &persona) {
    bool quedan = aumentarCantidad(-1);
    if (quedan) {
        persona.setDamage(2);
    }
    return quedan;
}
