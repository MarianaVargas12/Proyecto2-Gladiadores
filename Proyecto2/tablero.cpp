#include "tablero.h"
#include "iostream"
using namespace std;

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
        if(xRand == 0 && yRand == 0){
            qDebug()<<"No se pudo generar la torre ya que coincidia con el punto de incio";
        }
        else if (xRand == 9 && yRand == 9) {
            qDebug()<<"No se pudo generar la torre ya que coincidia con el punto Final";
        }
        else{
            if(cuadricula[xRand][yRand]->ocupado == false){
                torre* torreRandom = new torre();
                torreRandom->setX(cuadricula[xRand][yRand]->getX());
                torreRandom->setY(cuadricula[xRand][yRand]->getY());
                torreRandom->actualizarCuadrosAlcance();
                cuadricula[xRand][yRand]->ocupado = true;
                listaTorres->Add(torreRandom);
            }
        }
    }
}

void Tablero::generarMatriz()
{
    for (int i = 0;i<10;i++) {
        cout<<""<<endl;
        for (int j = 0;j<10;j++) {
            if(Tablero::getInstance().cuadricula[j][i]->ocupado == true){

                for (Node* nodoTorre = Tablero::getInstance().listaTorres->getFirst(); nodoTorre != nullptr ; nodoTorre = nodoTorre->getNext()){
                    torre* TorrePrueba = (torre*)nodoTorre->getData();
                    if (TorrePrueba->getX() == Tablero::getInstance().cuadricula[j][i]->getX() && TorrePrueba->getY() == Tablero::getInstance().cuadricula[j][i]->getY()){
                        cout<<TorrePrueba->tipo<<",";
                    }
                }
            }
            else {
                cout<<"0"<<",";
            }
        }
    }
}
