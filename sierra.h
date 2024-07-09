#ifndef SIERRA_H
#define SIERRA_H

#include "item.h"
#include "cartuchos.h"
#include "persona.h"

class Sierra: public Item
{
public:
    Sierra(int cantidad, enum Tipos nombre);
    bool usar(Cartuchos &cartuchos, Persona &persona);
};

#endif // SIERRA_H
