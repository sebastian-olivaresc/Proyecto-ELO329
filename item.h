#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "persona.h"
#include "cartuchos.h"

using namespace std;

class Persona;

class Item {
private:
    int cantidad;
    string nombre;

public:
    Item(int cantidad, string nombre);
    string usar(Cartuchos *cartuchos, Persona *personaje, string current);
    void usar(Persona *personaje);

    //-----Setters------
    void setCantidad(int cantidad);
    void setNombre(string nombre);
    //------------------

    //-----Getters------
    int getCantidad();
    string getNombre();
    //------------------

    bool aumentarCantidad(int cantidad);
};

#endif // ITEM_H
