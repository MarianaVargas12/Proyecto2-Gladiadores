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
    for ( int x = 0;x<20; x++) {
        Tablero::getInstance().generarTorre();
    }

    Tablero::getInstance().imprimirMatriz();
    cout<<"\n....................."<<endl;
    Tablero::getInstance().moverTorres();

    Tablero::getInstance().imprimirMatriz();

//    for (Node* nodoTorre = Tablero::getInstance().listaTorres->getFirst();nodoTorre!=nullptr;nodoTorre=nodoTorre->getNext()) {
//        torre* torreA = (torre*)nodoTorre->getData();
//            cout<<"Torre = X: "<<torreA->getX()/60<<"Y: "<<torreA->getY()/60<<endl;
//        for (Node* cuadroAdyacente = torreA->cuadrosAlcance.getFirst();cuadroAdyacente!=nullptr;cuadroAdyacente = cuadroAdyacente->getNext()) {
//            cout<<"X:"<<((cuadro*)cuadroAdyacente->getData())->getX()/60<<" Y:"<<((cuadro*)cuadroAdyacente->getData())->getY()/60<<endl;
//        }
//        cout<<"........................"<<endl;
//   }

//    cout<<"....."<<endl;
//    Tablero::getInstance().imprimirMatriz();

//    MainWindow w;
//    w.show();

//    return a.exec();
}
