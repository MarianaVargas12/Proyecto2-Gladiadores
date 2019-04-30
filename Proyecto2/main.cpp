#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <stdlib.h>
#include "lista.h"
#include "poblacion.h"

int main(int argc, char *argv[])
{
    Poblacion* poblacion1=new Poblacion();
    poblacion1->poblacionInicial(5);
    poblacion1->seleccion();
    poblacion1->creacion(5);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
