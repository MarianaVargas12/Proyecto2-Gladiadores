#ifndef POBLACION_H
#define POBLACION_H
#include "gladiador.h"
#include "lista.h"
#include "nodo.h"

class Poblacion
{
private:
    int estadistica;
    int poblacion;
    Gladiador* seleccionado;
    Lista* Gladiadores;
    Gladiador* mejores[2];
    int datos[9];

public:
    Poblacion();
    void fitness();
    void poblacionInicial();
    void cruces();
    void seleccion();
    void insercion(Gladiador* nuevoGladiador);
    void mutacion();
    void creacion(int cantidad);
};

#endif // POBLACION_H
