#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[])
{
    Lista* prueba=new Lista();
    for (int i=0;i<6;i++) {
        prueba->random();
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
