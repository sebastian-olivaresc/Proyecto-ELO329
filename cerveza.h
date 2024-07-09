#ifndef CERVEZA_H
#define CERVEZA_H

#include "item.h"
#include "cartuchos.h"
#include "persona.h"

class Cerveza: public Item
{
public:
    Cerveza(int cantidad, enum Tipos nombre);
    bool usar(Cartuchos &cartuchos, Persona &persona);
};

#endif // CERVEZA_H
