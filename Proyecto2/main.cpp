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
#include "arduino.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(0));

    for ( int x = 0;x<50; x++) {
        Tablero::getInstance().generarTorre();
    }
    Poblacion* poblacion1=new Poblacion();
    poblacion1->poblacionInicial(5);
    Poblacion* poblacion2=new Poblacion();
    poblacion2->poblacionInicial(5);
    Gladiador* mejor1=poblacion1->mejor();
    Gladiador* mejor2=poblacion2->mejor();
    Tablero::getInstance().imprimirMatriz();
    bool flag = true;
    cout<<"\n....................."<<endl;
    //Tablero::getInstance().moverTorres();

    Pair src = make_pair(0, 0);
    Pair dest = make_pair(9, 9);
    Socket *sock = &Socket::getInstance();
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
    string aLcd = "";
    string atributos[10];
    atributos[0] = (" Vida:");
    atributos[1] = (" Id:");
    atributos[2] = (" Generacion:");
    atributos[4] = (" Velocidad:");
    atributos[3] = (" Fitness:");
    atributos[5] = (" troncoSuperior:");
    atributos[6] = (" troncoinferior:");
    atributos[7] = (" velocidad:");
    atributos[8] = (" generacion:");
    atributos[9] = (" fitness: ");


//    for (int i = 0; i<4 ; i++){
//        aLcd += atributos[i];
//        aLcd += mejor1->atributos[i];
//    }
//    aLcd += "*";
//    for (int i = 0; i<4 ; i++){
//        aLcd += atributos[i];
//        aLcd += mejor2->atributos[i];
//    }
//     arduino::getInstance().escribir(aLcd);

     while (sock->play){
         if (sock->turno != 0 && sock->turno%3 == 0){
             qDebug()<<"ITERACION 3";
             Tablero::getInstance().moverTorres();
             int** path= aStarSearch(Tablero::getInstance().cuadriculaInt, src, dest);
             int** back= solveMaze(Tablero::getInstance().cuadriculaInt);
             string mensaje = serial->serializarIteracion3(Tablero::getInstance().cuadriculaInt, path, back);
             string recibido = sock->escuchaEnvia(8080, mensaje);

         }
         else{
             qDebug()<<"CAMBIO";
             poblacion1->creacion(4);
             poblacion2->creacion(4);
             Gladiador* mejor1=poblacion1->mejor();
             Gladiador* mejor2=poblacion2->mejor();
             Tablero::getInstance().generarTorre();
             int** path= aStarSearch(Tablero::getInstance().cuadriculaInt, src, dest);
             int** back= solveMaze(Tablero::getInstance().cuadriculaInt);
             for (int i = 0; i<4 ; i++){
                 aLcd += atributos[i];
                 aLcd += mejor1->atributos[i];
             }
             aLcd += "*";
             for (int i = 0; i<4 ; i++){
                 aLcd += atributos[i];
                 aLcd += mejor2->atributos[i];
             }
             string mensaje = serial->serializarTableroGladiador(Tablero::getInstance().cuadriculaInt,mejor1->getEdad(),mejor2->getEdad(),mejor1->getEmocional(),mejor2->getEmocional(),mejor1->getCondicion(),mejor2->getCondicion(),mejor1->getResistencia(),mejor2->getResistencia(),mejor1->getVelocidad(),mejor2->getVelocidad(),mejor1->getGeneracion(),
                                                                                      mejor2->getGeneracion(),mejor1->getId(),mejor2->getId(),mejor2->getVida(),mejor2->getVida(),mejor1->getFitness(),mejor2->getFitness(),mejor1->getProbabilidad(),mejor2->getProbabilidad(),mejor1->getSuperior(),mejor2->getSuperior(),mejor1->getInferior(),mejor2->getInferior(),mejor1->getSupervivncia(),mejor2->getSupervivncia(),path,back);
             qDebug()<<"PASA";
             arduino::getInstance().escribir(aLcd);
             qApp->processEvents();
             qDebug()<< aLcd.c_str();
              bool mod3 = false;
              string recibido = sock->escuchaEnvia(8080, mensaje);
              qDebug()<<recibido.c_str();
              serial->DeserealizarPartida(recibido,&(sock->play),&(sock->turno),&mod3);

              aLcd ="";

         }


     }
     arduino::getInstance().escribir("  FIN DEL JUEGO * FIN DEL JUEGO");
     return a.exec();
    //return 0;
}
