#ifndef GENERACION_H
#define GENERACION_H
#include "gladiador.h"
#include "lista.h"

class Generacion
{
    int generacion;
    int estadistica;
    int poblacion;
    Gladiador* seleccionado;
    Lista* nuevaGeneracion;

public:
    Generacion();
    void cruces();
    void seleccion();
    void insercion();
    void mutacion();
    void creacion(int cantidad);

};

#endif // GENERACION_H
