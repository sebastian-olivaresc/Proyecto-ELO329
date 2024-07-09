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
