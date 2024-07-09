#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include "cartuchos.h"
#include "item.h"

class Item;
class Persona;

using namespace std;

class Inventario {
private:
    vector<Item*> *inventario;

public:
    void addItem(Item *item);
    bool usarItem(enum Tipos item, Cartuchos &cartuchos, Persona &persona);
};

#endif // INVENTARIO_H
