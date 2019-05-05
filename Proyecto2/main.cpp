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
    Tablero::getInstance().generarMatriz();

    for (Node* nodoTorre = Tablero::getInstance().listaTorres->getFirst();nodoTorre!=nullptr;nodoTorre=nodoTorre->getNext()) {
        torre* torreA = (torre*)nodoTorre->getData();
        torreA->moverse();
    }
    cout<<""<<endl;
    Tablero::getInstance().generarMatriz();
    int mat[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
    string mensaje = serializador::getInstance().serializarTableroGladiador(mat,35,10,80,20,10,1,10001,80,60);
    Socket::getInstance().escuchaEnvia(8080, mensaje);

//    MainWindow w;
//    w.show();

//    return a.exec();
}
