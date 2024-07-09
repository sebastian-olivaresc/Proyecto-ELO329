
#include "inventario.h"

void Inventario::addItem(Item *item) {
    this->inventario->push_back(item);
}

bool Inventario::usarItem(enum Tipos item, Cartuchos &cartuchos, Persona &persona) {
    for (auto in : *inventario) {
        if (item == in->getNombre()) {
            in->usar(cartuchos, persona);
            return true;
        }
    }
    return false;

}
