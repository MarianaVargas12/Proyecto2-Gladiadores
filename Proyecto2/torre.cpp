#include "torre.h"
#include <cstdlib>
#include <ctime>
#include "tablero.h"
#include <QDebug>
torre::torre()
{
        int r= rand();
        this->tipo = (r%3)+1;

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

void torre::actualizarCuadrosAlcance(){
    int i = this->getX() /60;  // xActual / 60;
    int j = this->getY() /60; //yActual / 60;

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
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);//diagonal derecha abajo
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);//abajo
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
         cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
         cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
         cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);//izquierda
         cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
         cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);//diagonal izquierda arriba
    }
    else if(i>=1 && i <= 8 && j>=1 && j<=8){//centro
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);//diagonal derecha abajo
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);//abajo
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);//diagonal izquierda abajo
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);//izquierda
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);//diagonal izquierda arriba
    }
    else {
       qDebug()<<"No se puede construir una torre en el punto de salida o el de llegada";
    }

}

void torre::moverse(){
    //numero random para la direccion en la que se va a mover
    int movimiento = rand()%4+1;
    /*1 arriba
     *2 derecha
     *3 abajo
     *4 izquieda
     */
    switch (movimiento) {//verifica que el campo al que se va a mover sea valido y no este ocupado
    case 1:
        if(this->getY() / 60 != 0 && Tablero::getInstance().cuadricula[this->getX()/60][this->getY()/60 - 1]->ocupado == false){
            Tablero::getInstance().cuadricula[this->getX()/60][this->getY()/60]->ocupado = false;
            this->setY(this->getY()-60);
            Tablero::getInstance().cuadricula[this->getX()/60][this->getY()/60]->ocupado = true;
        }
        break;
    case 2:
        if(this->getX() / 60 != 9 && Tablero::getInstance().cuadricula[this->getX()/60 + 1][this->getY()/60]->ocupado == false){
            Tablero::getInstance().cuadricula[this->getX()/60][this->getY()/60]->ocupado = false;
            this->setX(this->getX()+60);
            Tablero::getInstance().cuadricula[this->getX()/60][this->getY()/60]->ocupado = true;
        }
        break;
    case 3:
        if(this->getY() / 60 != 9 && Tablero::getInstance().cuadricula[this->getX()/60][this->getY()/60 + 1]->ocupado == false){
            Tablero::getInstance().cuadricula[this->getX()/60][this->getY()/60]->ocupado = false;
            this->setY(this->getY()+60);
            Tablero::getInstance().cuadricula[this->getX()/60][this->getY()/60]->ocupado = true;
        }
        break;
    case 4:
        if(this->getX() / 60 != 0 && Tablero::getInstance().cuadricula[this->getX()/60 - 1][this->getY()/60]->ocupado == false){
            Tablero::getInstance().cuadricula[this->getX()/60][this->getY()/60]->ocupado = false;
            this->setX(this->getX()-60);
            Tablero::getInstance().cuadricula[this->getX()/60][this->getY()/60]->ocupado = true;
        }
        break;
    }
    actualizarCuadrosAlcance();
}

