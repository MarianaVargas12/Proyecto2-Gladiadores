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
#include "serializador.h"


int main(int argc, char *argv[])
{
    srand(time(0));
   // QApplication a(argc, argv);
   //Tablero *tablero = new Tablero();
    for ( int x = 0;x<10; x++) {
        Tablero::getInstance().generarTorre();
    }
    int grid[ROW][COL] =
        {
            { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
            { 1, 0, 1, 0, 1, 1, 1, 0, 1, 0 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
            { 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
            { 0, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            { 0, 1, 1, 0, 0, 0, 1, 0, 0, 1 },
            { 0, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
        };

    Tablero::getInstance().imprimirMatriz();
        // Source is the left-most bottom-most corner
        Pair src = make_pair(8, 0);

        // Destination is the left-most top-most corner
        Pair dest = make_pair(0, 0);

        aStarSearch(grid, src, dest);

/*
    Poblacion* poblacion1=new Poblacion();
    poblacion1->poblacionInicial(5);
    poblacion1->seleccion();
    poblacion1->creacion(5);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Tablero::getInstance().generarTorre();

    for (Node* nodoTorre = Tablero::getInstance().listaTorres->getFirst();nodoTorre!=nullptr;nodoTorre=nodoTorre->getNext()) {
        torre* torreA = (torre*)nodoTorre->getData();
        torreA->moverse();
    }
    cout<<""<<endl;
    Tablero::getInstance().generarMatriz();
    int mat[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
    string mensaje = serializador::getInstance().serializarTableroGladiador(mat,35,10,80,20,10,1,10001,80,60,20,30,15,1);
    Socket *sock = &Socket::getInstance();
    serializador *serial = &serializador::getInstance();
    bool mod3 = false;

    while (sock->play){
        serial->DeserealizarPartida(sock->escuchaEnvia(8080, mensaje),&(sock->play),&(sock->turno),&mod3);
        if(sock->turno % 3 ==0){
            qDebug()<<"\nModulo 3";
        }

    }


//    MainWindow w;
//    w.show();

//    return a.exec();*/
}

