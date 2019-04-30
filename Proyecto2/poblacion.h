#ifndef POBLACION_H
#define POBLACION_H
#include "gladiador.h"
#include "lista.h"
#include "nodo.h"
#include <iostream>
using namespace std;

class Poblacion
{
private:
    int estadistica;
    int poblacion;
    int generacion;
    Gladiador* seleccionado;
    Lista* Gladiadores = new Lista();
    Gladiador* mejores[2];
    int datos[9];

public:
    Poblacion();
    void poblacionInicial(int cantidad);
    void cruces();
    void seleccion();
    void insercion(Gladiador* nuevoGladiador);
    void mutacion();
    void creacion(int cantidad);
};

#endif // POBLACION_H
