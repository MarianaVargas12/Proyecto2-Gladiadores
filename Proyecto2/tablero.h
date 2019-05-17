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
    int cuadriculaInt[10][10];
    //!
    //! \brief Tablero construye un tablero y le asigna el x,y a cada cuadro de la matriz
    //!
    Tablero();
    //!
    //! \brief generarTorre crea una torre y la coloca en algun lugar aleatorio del tablero
    //!
    void generarTorre();
    //!
    //! \brief generarMatriz imprime en consola la matriz del tablero
    //!
    void imprimirMatriz();
    //!
    //! \brief moverTorres mueve todas las torres del tablero
    //!
    void moverTorres(int x,int y);
    //!
    //! \brief actualizarMatricula actualiza la matriz de enteros
    //!
    void actualizarMatriz();
    int** backtracking();
    bool visitado(int i, int j, int max, int visitados[][2]);
    LinkedList *listaTorres = new LinkedList();
};

#endif // TABLERO_H
