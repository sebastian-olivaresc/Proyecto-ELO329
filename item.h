#ifndef ITEM_H
#define ITEM_H

#include "cartuchos.h"

class Persona;

using namespace std;

enum Tipos {
    LUPA,
    CIGARROS,
    CERVEZA,
    SIERRA,
    ESPOSAS,
};

class Item {
private:
    int cantidad;
    enum Tipos nombre;

public:
    Item(int cantidad, enum Tipos nombre);
    //string usar(Cartuchos *cartuchos, Persona *personaje, string current);
    virtual bool usar(Cartuchos &cartuchos, Persona &persona) = 0;

    //-----Setters------
    void setCantidad(int cantidad);
    void setNombre(enum Tipos nombre);
    //------------------

    //-----Getters------
    int getCantidad();
    enum Tipos getNombre();
    //------------------

    bool aumentarCantidad(int cantidad);
};



#endif // ITEM_H
