#include "cartuchos.h"

Cartuchos::Cartuchos(int vacios, int cargados) :
    cargados(cargados),
    vacios(vacios) {
}

void Cartuchos::setCargados(int cantidad) {
    this->cargados = cantidad;
}

void Cartuchos::setVacios(int cantidad) {
    this->vacios = cantidad;
}

int Cartuchos::getCargados() {
    return cargados;
}

int Cartuchos::getVacios() {
    return vacios;
}

float Cartuchos::probabilidadVacios() {
    float value = static_cast<float>(vacios)/(cargados+vacios);
    return round(value * 100.0f)/100.0f;
}

float Cartuchos::probabilidadCargados() {
    float value = static_cast<float>(cargados)/(cargados+vacios);
    return round(value * 100.0f)/100.0f;
}

bool Cartuchos::aumentarCargados(int cantidad) {
    int current = getCargados();
    if (current + cantidad >= 0) {
        setCargados(current + cantidad);
        return true;
    }
    return false;
}

bool Cartuchos::aumentarVacios(int cantidad) {
    int current = getVacios();
    if (current + cantidad >= 0) {
        setVacios(current + cantidad);
        return true;
    }
    return false;
}

bool Cartuchos::descontarCartucho(string current) {
    if (current == "vacios") {
        return aumentarVacios(-1);
    }
    else {
        return aumentarCargados(-1);
    }
}

void Cartuchos::reset() {
    setVacios(0);
    setCargados(0);
}

