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
    void backtracking();
    void pathfinding();
    bool ruta();
    bool visitado(int i, int j, int max, int visitados[][2]);
    LinkedList *listaTorres = new LinkedList();
};

#endif // TABLERO_H
