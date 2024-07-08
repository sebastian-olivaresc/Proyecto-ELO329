#include "persona.h"
#include "gameoverwindow.h"  // Incluye el encabezado de la nueva ventana
#include <QApplication>

Persona::Persona(Inventario *inventario, int vidas, int damage) :
    inventario(inventario),
    vidas(vidas),
    damage(damage) {
}

//---Setters---
void Persona::setInventario(Inventario *inventario) {
}

void Persona::setVida(int vida) {
    this->vidas = vida;
}

void Persona::setDamage(int valor) {
    this->damage = valor;
}
//---Setters---

//---Getters---
Inventario *Persona::getInventario() {
}

int Persona::getVida() {
    return vidas;
}

int Persona::getDamage() {
    return damage;
}
//---Getters---

void Persona::aumentarVida(int cantidad) {
    int current = getVida();
    if (current + cantidad <= 0) {
        setVida(0);

        // Crear y mostrar la ventana de Game Over
        GameOverWindow gameOver;
        gameOver.exec();  // Utiliza exec() para mostrar el diálogo de manera modal

    } else {
        setVida(current + cantidad);
    }
}
