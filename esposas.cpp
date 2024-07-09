#include "esposas.h"


Esposas::Esposas(int cantidad, enum Tipos nombre):
    Item(cantidad, nombre){
}

bool Esposas::usar(Cartuchos &cartuchos, Persona &persona) {
    bool quedan = aumentarCantidad(-1);
    if (quedan) {
        /*
         * mostrar dos veces ventana para
         * verificar disparo
         * abrir, cerrar, abrir...
         */
    }
    return quedan;
}
