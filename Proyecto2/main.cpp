#include "mainwindow.h"
#include <QApplication>
#include "tablero.h"
#include "iostream"
#include <ctime>
#include "linkedlist.h"
#include "torre.h"
using namespace std;
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

//    MainWindow w;
//    w.show();

//    return a.exec();
}
