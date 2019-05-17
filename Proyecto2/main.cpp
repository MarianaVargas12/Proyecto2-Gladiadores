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
    for ( int x = 0;x<25; x++) {
        Tablero::getInstance().generarTorre();
    }

    Poblacion* poblacion1;//=new Poblacion();
   // poblacion1->poblacionInicial(5);
    Poblacion* poblacion2;//=new Poblacion();
   // poblacion2->poblacionInicial(5);
    Gladiador* mejor1;//=poblacion1->mejor();
    Gladiador* mejor2;//=poblacion2->mejor();
    Tablero::getInstance().imprimirMatriz();
    bool flag = true;
    bool inicial = true;
    bool mod3 = true;
    int envio[2];
    cout<<"\n....................."<<endl;
    //Tablero::getInstance().moverTorres();

    Pair src = make_pair(0, 0);
    Pair dest = make_pair(9, 9);
    Socket *sock = &Socket::getInstance();
    serializador *serial = &serializador::getInstance();
    int** path= aStarSearch(Tablero::getInstance().cuadriculaInt, src, dest);
    int** back= solveMaze(Tablero::getInstance().cuadriculaInt,0,0);
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
    atributos[7] = (" Id:");
    atributos[3] = (" Gen:");
    atributos[4] = (" Velocidad:");
    atributos[1] = (" Fitness:");
    atributos[5] = (" troncoSuperior:");
    atributos[6] = (" troncoinferior:");
    atributos[2] = (" velocidad:");
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
         if (inicial){
             qDebug()<<"INICIAL";
             poblacion1=new Poblacion();
             poblacion1->poblacionInicial(5);
             poblacion2=new Poblacion();
             poblacion2->poblacionInicial(5);
             mejor1=poblacion1->mejor();
             mejor2=poblacion2->mejor();
             inicial = false;
         }
         if (sock->turno != 0 and sock->turno%3 == 0){
             qDebug()<<"ITERACION 3";
             if (flag){
                 Tablero::getInstance().moverTorres(path[1][0],path[1][1]);
                 src = make_pair(path[1][0], path[1][1]);
                 path= aStarSearch(Tablero::getInstance().cuadriculaInt, src, dest);
                 back= solveMaze(Tablero::getInstance().cuadriculaInt,path[1][0],path[1][1]);
                 envio[0] = path[0][0];
                 envio[1] = path[0][1];
                 cout<<"Logro mover torres";

             }
             else{
                 cout<<"else";
                 Tablero::getInstance().moverTorres(back[1][0],back[1][1]);
                 src = make_pair(back[1][0], back[1][1]);
                 path= aStarSearch(Tablero::getInstance().cuadriculaInt, src, dest);
                 back= solveMaze(Tablero::getInstance().cuadriculaInt,back[1][0],back[1][1]);
                 envio[0] = back[0][0];
                 envio[1] = back[0][1];
                 cout<<"Logro mover torres";
             }
//             src = make_pair(path[1][0], path[1][1]);
//             path= aStarSearch(Tablero::getInstance().cuadriculaInt, src, dest);
//             back= solveMaze(Tablero::getInstance().cuadriculaInt,back[1][0],back[1][1]);
//             cout<<"Logro mover torres";
             string mensaje = serial->serializarIteracion3(Tablero::getInstance().cuadriculaInt,mejor1->getEdad(),mejor2->getEdad(),mejor1->getEmocional(),mejor2->getEmocional(),mejor1->getCondicion(),mejor2->getCondicion(),mejor1->getResistencia(),mejor2->getResistencia(),mejor1->getVelocidad(),mejor2->getVelocidad(),mejor1->getGeneracion(),
                                                           mejor2->getGeneracion(),mejor1->getId(),mejor2->getId(),mejor1->getVida(),mejor2->getVida(),mejor1->getFitness(),mejor2->getFitness(),mejor1->getProbabilidad(),mejor2->getProbabilidad(),mejor1->getSuperior(),mejor2->getSuperior(),mejor1->getInferior(),mejor2->getInferior(),mejor1->getSupervivncia(),mejor2->getSupervivncia(),path,back,envio);
             string recibido = sock->escuchaEnvia(8080, mensaje);
             qDebug()<<recibido.c_str()<<"RECIBIDO";
             serial->DeserealizarPartida(recibido,&(sock->play),&(sock->turno),&mod3);
             if (mod3){
                 src = make_pair(0, 0);
                 path= aStarSearch(Tablero::getInstance().cuadriculaInt, src, dest);
                 back= solveMaze(Tablero::getInstance().cuadriculaInt,0,0);
                 cout<<"murio"<<endl;
                 flag = false;

             }

         }
         else{
             qDebug()<<"CAMBIO";
             src = make_pair(0, 0);
             mejor1=poblacion1->mejor();
             mejor2=poblacion2->mejor();
             Tablero::getInstance().generarTorre();
             path= aStarSearch(Tablero::getInstance().cuadriculaInt, src, dest);
             back= solveMaze(Tablero::getInstance().cuadriculaInt,0,0);
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
                                                                                      mejor2->getGeneracion(),mejor1->getId(),mejor2->getId(),mejor1->getVida(),mejor2->getVida(),mejor1->getFitness(),mejor2->getFitness(),mejor1->getProbabilidad(),mejor2->getProbabilidad(),mejor1->getSuperior(),mejor2->getSuperior(),mejor1->getInferior(),mejor2->getInferior(),mejor1->getSupervivncia(),mejor2->getSupervivncia(),path,back);
             poblacion1->creacion(4);
             poblacion2->creacion(4);
             qDebug()<<"PASA";
             arduino::getInstance().escribir(aLcd);
             qApp->processEvents();
             qDebug()<< aLcd.c_str();
              string recibido = sock->escuchaEnvia(8080, mensaje);
              qDebug()<<recibido.c_str();
              serial->DeserealizarPartida(recibido,&(sock->play),&(sock->turno),&mod3);

              aLcd ="";
              back[1][0]=0;
              back[1][1]=0;
              path[1][0]=0;
              path[1][1]=0;
              flag = true;
         }


     }
     string enviar = serial->serializarGrafico(poblacion1->getGrafico(),poblacion2->getGrafico());
     Socket::getInstance().escuchaEnvia(8080,enviar);
     qApp->processEvents();
     arduino::getInstance().escribir("  FIN DEL JUEGO * FIN DEL JUEGO");
     return a.exec();
    //return 0;

}
