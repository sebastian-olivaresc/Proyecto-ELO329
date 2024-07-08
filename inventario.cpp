
#include "inventario.h"
#include "item.h"


void Inventario::addItem(Item *item) {
    this->inventario->push_back(item);
}

Item *Inventario::usar(string item) {
    for (auto in : *inventario) {
        if (item == in->getNombre())
            return in;
    }
    return nullptr;

}
