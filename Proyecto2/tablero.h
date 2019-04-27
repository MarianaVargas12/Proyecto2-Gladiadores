#ifndef TABLERO_H
#define TABLERO_H
#include "cuadro.h"
#include <cstdlib>
#include "torre.h"

class Tablero
{
public:
    static Tablero& getInstance(){
               static Tablero instance;
               return instance;
}
    cuadro* cuadricula[10][10];
    Tablero();
    void generarTorre();
};

#endif // TABLERO_H
