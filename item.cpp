// Item.cpp - Implementacion clase Item

#include "item.h"

Item::Item(int cantidad, string nombre) :
    cantidad(cantidad),
    nombre(nombre) {
}

//---------Setters-----------
void Item::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

void Item::setNombre(string nombre) {
    this->nombre = nombre;
}
//---------------------------

//---------Getters-----------
int Item::getCantidad() {
    return cantidad;
}

string Item::getNombre() {
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
