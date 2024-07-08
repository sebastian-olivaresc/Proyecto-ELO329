#ifndef CARTUCHOS_H
#define CARTUCHOS_H

#include <string>
#include <cmath>

using namespace std;

class Cartuchos {
private:
    int cargados;
    int vacios;

    //---Setters---
    void setCargados(int cantidad);
    void setVacios(int cantidad);
    //---Setters---

public:
    Cartuchos(int vacios, int cargados);

    //---Getters---
    int getCargados();
    int getVacios();
    //---Getters---

    bool aumentarCargados(int cantidad);
    bool aumentarVacios(int cantidad);
    float probabilidadVacios();
    float probabilidadCargados();

    bool descontarCartucho(string current);
};

#endif // CARTUCHOS_H