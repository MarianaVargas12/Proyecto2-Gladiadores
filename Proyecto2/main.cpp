#include "mainwindow.h"
#include <QApplication>
#include "tablero.h"
#include "iostream"
#include <ctime>
#include "linkedlist.h"
#include "torre.h"
using namespace std;
#include <stdlib.h>
#include "lista.h"
#include "poblacion.h"
#include "astar.cpp"
#include "socket.h"
#include "backtracking.cpp"
#include "serializador.h"


int main(int argc, char *argv[])
{
    srand(time(0));

    for ( int x = 0;x<50; x++) {
        Tablero::getInstance().generarTorre();
    }
    Poblacion* poblacion1=new Poblacion();
    poblacion1->poblacionInicial(5);
    Poblacion* poblacion2=new Poblacion();
    poblacion2->poblacionInicial(5);
    poblacion1->creacion(5);
    poblacion2->creacion(5);
    Gladiador* mejor1=poblacion1->mejor();
    Gladiador* mejor2=poblacion2->mejor();

    cout<<"\n....................."<<endl;
    //Tablero::getInstance().moverTorres();

    Pair src = make_pair(0, 0);
    Pair dest = make_pair(9, 9);
    //Socket *sock = &Socket::getInstance();
    serializador *serial = &serializador::getInstance();
    int** path= aStarSearch(Tablero::getInstance().cuadriculaInt, src, dest);
    int** back= solveMaze(Tablero::getInstance().cuadriculaInt);
    for(int i =0; i<30;i++){
        if (back[i][0]==9 && back[i][1]==9){
            cout<<back[i][0]<<back[i][1];
            break;
        }
        else{
            cout<<back[i][0]<<back[i][1]<<"-->";
        }
    }
    string mensaje = serial->serializarTableroGladiador(Tablero::getInstance().cuadriculaInt,mejor1->getEdad(),mejor2->getEdad(),mejor1->getEmocional(),mejor2->getEmocional(),mejor1->getCondicion(),mejor2->getCondicion(),mejor1->getResistencia(),mejor2->getResistencia(),mejor1->getVelocidad(),mejor2->getVelocidad(),mejor1->getGeneracion(),
                                                                             mejor2->getGeneracion(),mejor1->getId(),mejor2->getId(),mejor1->getVida(),mejor2->getVida(),mejor1->getFitness(),mejor2->getFitness(),mejor1->getProbabilidad(),mejor2->getProbabilidad(),mejor1->getSuperior(),mejor2->getSuperior(),mejor1->getInferior(),mejor2->getInferior(),mejor1->getSupervivncia(),mejor2->getSupervivncia(),path,back);
}
