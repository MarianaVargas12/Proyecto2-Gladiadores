#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include <iostream>
using namespace std;

class Lista
{
private:
    Nodo* Head;
    int cantidad;

public:
    Lista();
    Nodo* getHead();
    void agregarIinicio(Nodo* nuevoNodo);
    void agregarFinal(Nodo* nuevoNodo);
    Nodo* solicitar(Nodo* nodoBuscar);
    int getcantidad();
    void imprimir();
};

#endif // LISTA_H
