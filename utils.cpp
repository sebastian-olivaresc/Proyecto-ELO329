#include "utils.h"
#include <iostream>
using namespace std ;

// Titulo: elegirDisparo
// Parametros: Cartuchos *cartuchos 
// Output: string 
// Funcion: Esta funcion decide cual es el mejor disparo que puede realizar el
// Player. 
// Si es mas probable que sea vacio, se sugiere disparar al jugador
// Si es mas probable que sea cargado, se sugiere disparar al dealer
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


// Titulo: realizarDescuentos 
// Parametros:  int &ronda,
//              bool disparo,
//              string personaRecibe,
//              string personaDispara,
//              Cartuchos *cartuchos,
//              Persona *player,
//              Persona *dealer
// Output: bool 
// Funcion: Esta funcion realiza los decuentos de los cartuchos y de las vidas.
// Se retorna true si se le gana al dealer pasando a la siguiente ronda.
// Se retorna false, en el caso de que no avance de ronda.
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


// Titulo: valoresRonda
// Parametros:  int ronda,
//              Persona **player,
//              Persona **dealer
// Output: void
// Funcion: Esta funcion setea los valores de el player y el dealer al inicio de
// cada ronda, la cantidad de vidas, reinicia el inventario, reinicia el damage
// a 1.
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

// Titulo: floatToString
// Parametros: float value, int precision
// Output: std::string
// Funcion: Esta funcion fromatea un valor con una dada cantidad de decimales
std::string floatToString(float value, int precision) {
    std::string str = std::to_string(value);
    str = str.substr(0, str.find('.') + precision + 1); // precision total de 2 decimales
    str.erase(str.find_last_not_of('0') + 1, std::string::npos); // Eliminar ceros a la derecha
    if (str.back() == '.') {
        str.pop_back(); // Eliminar el punto si es el último carácter
    }
    return str;
}

