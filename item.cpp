// Item.cpp - Implementacion clase Item

#include "item.h"

Item::Item(int cantidad, enum Tipos nombre) :
    cantidad(cantidad),
    nombre(nombre) {
}

//---------Setters-----------
void Item::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

void Item::setNombre(enum Tipos nombre) {
    this->nombre = nombre;
}
//---------------------------

//---------Getters-----------
int Item::getCantidad() {
    return cantidad;
}

enum Tipos Item::getNombre() {
    return nombre;
}
//---------------------------


// Titulo: aumentarCantidad 
// Parametros: int cantidad 
// Output: bool 
// Funcion: Esta funcion aumenta la cantidad del item, pudiendo ser positivo o
// negativo. 
// retorna true si se aumenta sin problemas.
// retrona false si se resta hasta una cantidad negativa.
bool Item::aumentarCantidad(int cantidad) {
    int current = getCantidad();
    if (current + cantidad >= 0) {
        setCantidad(current + cantidad);
        return true;
    }
    else {
        return false;
    }
}
