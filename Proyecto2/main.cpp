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


    for (int x = 0;x<10;x++) {
        Tablero::getInstance().generarTorre();
    }
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

    for (Node* torreA = Tablero::getInstance().listaTorres.getFirst();torreA!=nullptr; torreA = torreA->getNext()) {
        torre* asd = ((torre*)torreA);
        cout<<"Tipo de torre "<<asd->getX() <<endl;
    }

//    MainWindow w;
//    w.show();

//    return a.exec();
}
