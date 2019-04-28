#include "torre.h"
#include <cstdlib>
#include <ctime>
#include "tablero.h"
#include <QDebug>
torre::torre()
{
        srand(time(0));
        tipo = rand()%3+1;
}

int torre::getX() const
{
    return x;
}

void torre::setX(int value)
{
    x = value;
}

int torre::getY() const
{
    return y;
}

void torre::setY(int value)
{
    y = value;
}

void torre::actualizarCuadrosAlcance(int xActual, int yActual){
    int i = xActual / 60;
    int j = yActual / 60;

    if(i==9 && j == 0){//esquina derecha superior
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
    }
    else if(i==0 && j==9){//esquina izquierda inferior
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);
    }
    else if(i==0 && j >= 1 && j <=8){//pegando a la izquierda
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
    }
    else if(i==9 && j >=1 && j <=8){//pegando a la derecha
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
    }
    else if(i>=0 && i<=8 && j==0){//pegando arriba
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);
    }
    else if(i>=0 && i<=8 && j==9){//pegando abajo
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);
    }
    else if(i>=1 && i <= 8 && j>=1 && j<=8){//centro
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);
    }
    else {
       qDebug()<<"No se puede construir una torre en el punto de salida o el de llegada";
    }
}

