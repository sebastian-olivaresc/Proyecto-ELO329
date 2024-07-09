#include "cerveza.h"

Cerveza::Cerveza(int cantidad, enum Tipos nombre):
    Item(cantidad, nombre){
}

bool Cerveza::usar(Cartuchos &cartuchos, Persona &persona) {
    bool quedan = aumentarCantidad(-1);
    if (quedan) {
        /*
         *  mostrar ventana para verificar
         *  que cartuchos se descarto
         *
         *  decontarCartuchos()
        */
    }
    return quedan;
}
