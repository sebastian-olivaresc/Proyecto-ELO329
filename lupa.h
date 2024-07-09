#ifndef LUPA_H
#define LUPA_H

#include "item.h"
#include "cartuchos.h"
#include "persona.h"

class Lupa: public Item
{
public:
    Lupa(int cantidad, enum Tipos nombre);
    bool usar(Cartuchos &cartuchos, Persona &persona);
};

#endif // LUPA_H
