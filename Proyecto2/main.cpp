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


int main(int argc, char *argv[])
{
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


    for (int i = 0;i<10;i++) {
        cout<<""<<endl;
        for (int j = 0;j<10;j++) {
            if(Tablero::getInstance().cuadricula[j][i]->ocupado == true){
                cout<<"1"<<",";
            }
            else {
                cout<<"0"<<",";
            }
        }
    }

    for (Node* torreA = Tablero::getInstance().listaTorres->getFirst();torreA!=nullptr; torreA = torreA->getNext()) {
        torre* asd = ((torre*)torreA->getData());
        cout<<asd->getX()/60<<","<<asd->getY()/60<<endl;
        for (Node* cuadroA = asd->cuadrosAlcance.getFirst();cuadroA!=nullptr;cuadroA=cuadroA->getNext()) {
            cuadro* cuadroB = (cuadro*)cuadroA->getData();
            qDebug()<<cuadroB->getX()/60<<","<<cuadroB->getY()/60;
        }
    }


//    MainWindow w;
//    w.show();

//    return a.exec();*/
}

