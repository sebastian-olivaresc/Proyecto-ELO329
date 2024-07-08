#include "utils.h"
#include <iostream>
using namespace std ;

/*
 * Decide cual es el disparo mejor para el jugador
 * si es mas probable que sea vacio, se sugiere disparar al jugador
 * si es mas probable que sea cargado, se sugiere disparar al dealer
*/
string elegirDisparo(Cartuchos *cartuchos) {
    float vacios = cartuchos->probabilidadVacios();
    float cargados = cartuchos->probabilidadCargados();
    cout << "vacios: " << vacios << endl;
    cout << "cargados: " << cargados << endl;
    if (vacios > cargados) {
        return "Player";
    }
    else {
        return "Dealer";
    }
}


/*
 * Realiza los descuentos despues de que el usuario
 * entregue la respuesta que realiza el juego
 * true significa vacio
 */
void realizarDescuentos(bool disparo,
                        string persona,
                        Cartuchos *cartuchos,
                        Persona *player,
                        Persona *dealer,
                        int descuento) {

    if (disparo) {
        cartuchos->aumentarVacios(-1);
    }
    else {
        cartuchos->aumentarCargados(-1);
    }

    if (!disparo && persona == "Player") {
        player->aumentarVida(-1*descuento);
    }
    else if (!disparo && persona == "Dealer"){
        dealer->aumentarVida(-1*descuento);
    }
}


// Setea los valores de los jugadores cada ronda
void valoresRonda(int ronda, Persona **player, Persona **dealer) {
    // Valores ronda 1
    if (ronda == 1) {
        *player = new Persona(nullptr, 3, 1);
        *dealer = new Persona(nullptr, 3, 1);
    }

    // Valores ronda 2

    // Valores ronda 3
}
