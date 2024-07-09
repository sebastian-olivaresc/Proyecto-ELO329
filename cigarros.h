#ifndef CIGARROS_H
#define CIGARROS_H

#include "item.h"
#include "cartuchos.h"
#include "persona.h"

class Cigarros : public Item
{
public:
    Cigarros(int cantidad, enum Tipos nombre);
    bool usar(Cartuchos &cartuchos, Persona &persona);
};

#endif // CIGARROS_H
