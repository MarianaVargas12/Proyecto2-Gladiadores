#ifndef TORRE_H
#define TORRE_H
#include "linkedlist.h"

class torre
{
private:
    int x,y;

public:
    //!
    //! \brief torre crea una torre de un tipo random
    //!
    torre();
    LinkedList cuadrosAlcance; //cuadros en los que llegan las flechas
    int tipo;
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    void moverse(int x,int y);
    void disparar();
    //!
    //! \brief actualizarCuadrosAlcance actualiza los cuadros que rodean a la torre segun su posicion
    //! \param xActual X en el que se encuentra la torre
    //! \param yActual Y en el que se encuentra la torre
    //!
    void actualizarCuadrosAlcance();
};

#endif // TORRE_H
