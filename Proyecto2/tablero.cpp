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
            xInicial+=60;
        }
        xInicial = 0;
        yInicial+= 60;

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
                cuadriculaInt[xRand][yRand] = torreRandom->tipo;
                listaTorres->Add(torreRandom);
            }
        }
    }
}

void Tablero::imprimirMatriz()
{
    for (int i = 0;i<10;i++) {
        cout<<""<<endl;
        for (int j = 0;j<10;j++) {
            if(Tablero::getInstance().cuadricula[i][j]->ocupado == true){
                for (Node* nodoTorre = Tablero::getInstance().listaTorres->getFirst(); nodoTorre != nullptr ; nodoTorre = nodoTorre->getNext()){
                    torre* TorrePrueba = (torre*)nodoTorre->getData();
                    if (TorrePrueba->getX() == Tablero::getInstance().cuadricula[i][j]->getX() && TorrePrueba->getY() == Tablero::getInstance().cuadricula[i][j]->getY()){
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

void Tablero::moverTorres()
{
    for(Node* nodoTorre = listaTorres->getFirst();nodoTorre != nullptr; nodoTorre = nodoTorre->getNext()){
        torre* torreAMover = (torre*)nodoTorre->getData();
        torreAMover->moverse();
    }
    actualizarMatriz();
}

void Tablero::actualizarMatriz()
{
    for (int i = 0;i<10;i++) {
        for (int j = 0;j<10;j++) {
            if(Tablero::getInstance().cuadricula[i][j]->ocupado == true){
                 for(Node* nodoTorre = listaTorres->getFirst();nodoTorre != nullptr; nodoTorre = nodoTorre->getNext()){
                     torre* torreAMover = (torre*)nodoTorre->getData();
                     if(torreAMover->getX()/60 == j && torreAMover->getY()/60 == i){
                        Tablero::getInstance().cuadriculaInt[i][j] = torreAMover->tipo;
                     }
                }
            }
            else{
                Tablero::getInstance().cuadriculaInt[i][j]=0;
            }
        }
    }
}

