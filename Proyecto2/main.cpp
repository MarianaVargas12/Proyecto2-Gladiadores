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

    for ( int x = 0;x<20; x++) {
        Tablero::getInstance().generarTorre();
    }

    Tablero::getInstance().imprimirMatriz();
    cout<<"\n....................."<<endl;
    Tablero::getInstance().moverTorres();
    Tablero::getInstance().imprimirMatriz();
    cout<<"\n....................."<<endl;
    for (int i = 0;i<10;i++) {
        for (int j = 0;j<10;j++) {
            cout<<Tablero::getInstance().cuadriculaInt[i][j];
        }
        cout<<""<<endl;
    }

}
