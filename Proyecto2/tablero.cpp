#include "tablero.h"

Tablero::Tablero()
{
    int xInicial = 0;
    int yInicial = 0;
    for (int i = 0; i < 10;i++) {
        for (int j = 0; j < 10;j++) {
            cuadro* nuevoCuadro = new cuadro();
            nuevoCuadro->setX(xInicial);
            nuevoCuadro->setY(yInicial);
            cuadricula[i][j] = nuevoCuadro;
            yInicial+=100;
        }
        yInicial = 0;
        xInicial+= 100;

    }
}

void Tablero::generarTorre()
{
    int xRand = rand()%10 +1;
    int yRand = rand()%10 +1;
    if(cuadricula[xRand][yRand]->ocupado == false){
        torre* torreRandom = new torre();
        torreRandom->setX(cuadricula[xRand][yRand]->getX());
        torreRandom->setY(cuadricula[xRand][yRand]->getY());
    }

}
