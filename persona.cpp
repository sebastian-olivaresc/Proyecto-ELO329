#include "persona.h"
#include "gameoverwindow.h"  // Incluye el encabezado de la nueva ventana
#include "winround.h" // header the ventana win round
#include <QApplication>

Persona::Persona(enum Nombre nombre, Inventario *inventario, int vidas, int damage) :
    nombre(nombre),
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
enum Nombre Persona::getNombre() {
    return this->nombre;
}

Inventario *Persona::getInventario() {
}

int Persona::getVida() {
    return vidas;
}

int Persona::getDamage() {
    return damage;
}
//---Getters---


// Titulo: aumentarVida 
// Parametros: int cantidad 
// Output: bool 
// Funcion: Esta funcion aumenta la vida de la persona, pudiendo ser el valor
// ingresado positivo o negativo. Ademas, se crea y muestra la pantalla de
// gameover si se acaban las vidas y la persona es player
bool Persona::aumentarVida(int cantidad) {
    int current = getVida();
    if (current + cantidad <= 0) {
        setVida(0);

        // El juego se acaba si el jugador llega a 0
        // Se avanza una ronda si el dealer llega a 0
        if (getNombre() == PLAYER) {
            // Crear y mostrar la ventana de Game Over
            GameOverWindow gameOver;
            gameOver.exec();  // Utiliza exec() para mostrar el diálogo de manera modal
        }
        else if (getNombre() == DEALER) {
            return true;
        }

    } else {
        setVida(current + cantidad);
    }
    return false;
}


// Titulo: usarItem 
// Parametros:  enum Tipos item,
//              Cartuchos &cartuchos, 
//              Persona &persona
// Output: bool 
// Funcion: Esta funcion realiza la accion de usar item del inventario dado por
// el parametro item.
bool Persona::usarItem(enum Tipos item, Cartuchos &cartuchos, Persona &persona) {
    inventario->usarItem(item, cartuchos, *this);
}
