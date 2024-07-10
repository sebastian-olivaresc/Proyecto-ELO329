
#include "inventario.h"

// Titulo: addItem 
// Parametros: Item *item
// Output: void
// Funcion: Esta funcion agrega un item al inventario
void Inventario::addItem(Item *item) {
    this->inventario->push_back(item);
}


// Titulo: usarItem 
// Parametros:  enum Tipos item,
//              Cartuchos &cartuchos,
//              Persona &persona
// Output: bool
// Funcion: Esta funcion busca un item en el inventario de una persona dada 
// y lo usa. 
// retorna true si quedaban items y se uso. 
// retorna false si no se usa porque no quedaban. 
bool Inventario::usarItem(enum Tipos item, Cartuchos &cartuchos, Persona &persona) {
    for (auto in : *inventario) {
        if (item == in->getNombre()) {
            in->usar(cartuchos, persona);
            return true;
        }
    }
    return false;

}
