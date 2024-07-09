#include "lupa.h"

Lupa::Lupa(int cantidad, enum Tipos nombre):
    Item(cantidad, nombre){
}

bool Lupa::usar(Cartuchos &cartuchos, Persona &persona) {
    bool quedan = aumentarCantidad(-1);
    if (quedan) {
        /*
         * puede ser misma ventana
         * que cerveza
         *
         * con texto cambiado
         */
    }
    return quedan;
}
