#ifndef ESPOSAS_H
#define ESPOSAS_H

#include "item.h"
#include "cartuchos.h"
#include "persona.h"

class Esposas: public Item
{
public:
    Esposas(int cantidad, enum Tipos nombre);
    bool usar(Cartuchos &cartuchos, Persona &persona);
};


#endif // ESPOSAS_H
