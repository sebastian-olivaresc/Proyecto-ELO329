#ifndef PERSONA_H
#define PERSONA_H


class Inventario;
class Persona
{
public:
    Persona (Inventario *inventario, int vidas, int damage);

    //---Setters---
    void setInventario(Inventario *inventario);
    void setVida(int vida);
    void setDamage(int valor);
    //---Setters---

    //---Getters---
    Inventario *getInventario();
    int getVida();
    int getDamage();
    //---Getters---

    void aumentarVida(int cantidad);

private:
    Inventario *inventario;
    int vidas;
    int damage;
};

#endif // PERSONA_H
