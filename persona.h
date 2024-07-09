#ifndef PERSONA_H
#define PERSONA_H

#include "item.h"
#include "inventario.h"

enum Nombre {
    PLAYER,
    DEALER,
};

class Persona
{
public:
    Persona (enum Nombre nombre, Inventario *inventario, int vidas, int damage);

    //---Setters---
    void setInventario(Inventario *inventario);
    void setVida(int vida);
    void setDamage(int valor);
    //---Setters---

    //---Getters---
    enum Nombre getNombre();
    Inventario *getInventario();
    int getVida();
    int getDamage();
    //---Getters---

    bool aumentarVida(int cantidad);

    bool usarItem(enum Tipos item, Cartuchos &cartuchos, Persona &persona);

private:
    enum Nombre nombre;
    Inventario *inventario;
    int vidas;
    int damage;
};

#endif // PERSONA_H
