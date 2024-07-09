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
bool realizarDescuentos(int &ronda,
                        bool disparo,
                        string personaRecibe,
                        string personaDispara,
                        Cartuchos *cartuchos,
                        Persona *player,
                        Persona *dealer) {

    bool nextRound = false;
    if (disparo) {
        cartuchos->aumentarVacios(-1);
    }
    else {
        cartuchos->aumentarCargados(-1);
    }


    int descuento = 1;

    if (!disparo && personaRecibe == "Player") {
        player->aumentarVida(-1*descuento);
    }
    else if (!disparo && personaRecibe == "Dealer"){
        nextRound = dealer->aumentarVida(-1*descuento);
    }

    // Resetea el damage, por si se uso sierra
    player->setDamage(1);
    dealer->setDamage(1);

    if (nextRound) {
        ronda++;
    }
    return nextRound;
}


// Setea los valores de los jugadores cada ronda
void valoresRonda(int ronda, Persona **player, Persona **dealer) {
    // Valores ronda 1
    if (ronda == 1) {
        *player = new Persona(PLAYER, nullptr, 3, 1);
        *dealer = new Persona(DEALER, nullptr, 3, 1);
    }

    // Valores ronda 2
    if (ronda == 2) {
        *player = new Persona(PLAYER, nullptr, 4, 1);
        *dealer = new Persona(DEALER, nullptr, 4, 1);
    }

    // Valores ronda 3
}
