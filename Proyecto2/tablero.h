#ifndef TABLERO_H
#define TABLERO_H
#include "cuadro.h"
#include <cstdlib>
#include "torre.h"
#include "linkedlist.h"

class Tablero
{
public:
    static Tablero& getInstance(){
               static Tablero instance;
               return instance;
}
    cuadro* cuadricula[10][10];
    //!
    //! \brief Tablero construye un tablero y le asigna el x,y a cada cuadro de la matriz
    //!
    Tablero();
    //!
    //! \brief generarTorre crea una torre y la coloca en algun lugar aleatorio del tablero
    //!
    void generarTorre();
    LinkedList listaTorres;
};

#endif // TABLERO_H
