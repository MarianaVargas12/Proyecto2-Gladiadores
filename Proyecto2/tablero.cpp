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
            yInicial+=60;
        }
        yInicial = 0;
        xInicial+= 60;

    }
}


void Tablero::generarTorre()
{

    int xRand = rand()%10;
    int yRand = rand()%10;
    if(xRand != 0 && yRand != 0 || xRand != 9 && yRand !=9){
        if(cuadricula[xRand][yRand]->ocupado == false){
            torre* torreRandom = new torre();
            torreRandom->setX(cuadricula[xRand][yRand]->getX());
            torreRandom->setY(cuadricula[xRand][yRand]->getY());
            torreRandom->actualizarCuadrosAlcance();
            cuadricula[xRand][yRand]->ocupado = true;
            listaTorres->Add(torreRandom);
        }
    }
    else {
        qDebug()<<"No se pudo generar la torre ya que coincidia con el punto de incio o el final";
    }
}
