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
    int j = this->getX() /60;  // xActual / 60;
    int i = this->getY() /60; //yActual / 60;

    if(i==9 && j == 0){//esquina derecha superior
        if(this->tipo ==1 ){
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
        }
        if(this->tipo ==2|| this->tipo ==3){

            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j+2]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+2]);

        }
    }
    else if(i==0 && j==9){//esquina izquierda inferior
        if(this->tipo ==1 ){
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);
        }
        if(this->tipo ==2|| this->tipo ==3){
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j-2]);
        cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-2]);
        }
    }
    else if(i==0 && j >= 1 && j <=8){//pegando a la izquierda
        if(i==0 && j == 1){//excepcion arriba
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);//abajo
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j+2]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+2]);//abajo
            }
        }
        else if (i==0 && j==8) { //excepcion abajo
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);//abajo
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-2]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j-2]);//diagonal derecha arriba
            }
        }
        else{
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);//abajo
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-2]); //arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j-2]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j+2]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+2]);//abajo
            }
        }
    }
    else if(i==9 && j >=1 && j <=8){//pegando a la derecha
        if(i==9 && j == 1){//excepcion arriba
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j+2]);//diagonal izquierda abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+2]);//abajo
            }
        }
        else if (i == 9 && j == 8) { //excepcion abajo
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-2]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j-2]);//diagonal izquierda arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j]);//izquierda
            }
        }
        else{
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-2]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j-2]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j+2]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+2]);
            }
        }
    }
    else if(i>=1 && i<=8 && j==0){//pegando arriba
        if(i==1 && j ==0){//excepcion izquierda
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+2]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j+2]);//diagonal derecha abajo
            }
        }
        else if (i==8 && j==0) {//excepcion derecha
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+2]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j+2]);//diagonal izquierda abajo
            }
        }
        else {
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j+2]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+2]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j+2]);
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j]);
            }
        }
    }
    else if(i>=1 && i<=8 && j==9){//pegando abajo
        if(i == 1 && j == 9){ //excepcion izquierda
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);//diagonal izquierda arriba
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-2]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j-2]);//diagonal derecha arriba
            }
        }
        else if (i == 8 && j == 9) { //excepcion derecha
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);//diagonal izquierda arriba
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-2]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j-2]);//diagonal izquierda arriba
            }
        }
        else{
             if(this->tipo ==1 ){
             cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
             cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
             cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);//izquierda
             cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
             cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);//diagonal izquierda arriba
             }
             if(this->tipo ==2|| this->tipo ==3){
             cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-2]);
             cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j]);
             cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j]);
             cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j-2]);
             cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j-2]);
             }
            }
    }
    else if(i>=1 && i <= 8 && j>=1 && j<=8){//centro
        if(i == 1 && j == 1){//excepcion izquierda arriba
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);//diagonal izquierda abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);//diagonal izquierda arriba
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j+2]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+2]);//abajo
            }

        }
        else if (i == 8 && j == 1) {//excepcion derecha arriba
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);//diagonal izquierda abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);//diagonal izquierda arriba
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+2]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j+2]);//diagonal izquierda abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j]);//izquierda
            }
        }
        else if (i == 1 && j == 8) {//excepcion izquierda abajo
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);//diagonal izquierda abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);//diagonal izquierda arriba
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-2]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j-2]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j]);//derecha
            }
        }
        else if (i == 8 && j == 8) {//excepcion derecha abajo
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);//diagonal izquierda abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);//diagonal izquierda arriba
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-2]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j-2]);//diagonal izquierda arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j]);//izquierda
            }
        }
        else if (i >= 2 && i <= 7 && j == 1) {//excepcion linea arriba
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);//diagonal izquierda abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);//diagonal izquierda arriba
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+2]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j+2]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j+2]);//diagonal izquierda abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j]);//derecha
            }
        }
        else if (i >= 2 && i <= 7 && j == 8) {//excepcion linea abajo
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);//diagonal izquierda abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);//diagonal izquierda arriba
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-2]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j-2]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j-2]);//diagonal izquierda arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j]);//derecha
            }
        }
        else if (i == 8 && j >= 2 && j <= 7) {//excepcion linea derecha
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);//diagonal izquierda abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);//diagonal izquierda arriba
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-2]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j-2]);//diagonal izquierda arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j+2]);//diagonal izquierda abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+2]);//abajo
            }
        }
        else if (i == 1 && j >= 2 && j <= 7) {//excepcion linea izquierda
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);//diagonal izquierda abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);//diagonal izquierda arriba
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-2]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j-2]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j+2]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+2]);//abajo
            }
        }
        else{
            if(this->tipo ==1 ){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-1]);//arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j+1]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+1][j-1]);//diagonal derecha arriba
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+1]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j+1]);//diagonal izquierda abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-1][j-1]);//diagonal izquierda arriba
            }
            if(this->tipo ==2|| this->tipo ==3){
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j-2]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j+2]);//diagonal derecha abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j]);//derecha
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i+2][j-2]);//diagonal derecha superior
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i][j+2]);//abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j+2]);//diagonal izquierda abajo
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j]);//izquierda
            cuadrosAlcance.Add(Tablero::getInstance().cuadricula[i-2][j-2]);//diagonal izquierda superior
            }
        }
    }

    else if(i == 0 && j == 0) {
       qDebug()<<"No se puede construir una torre en el punto de salida";
    }
    else {
       qDebug()<<"No se puede construir una torre en el punto de llegada";
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

        if(this->getY() / 60 != 0 && Tablero::getInstance().cuadricula[this->getY()/60-1][(this->getX()/60)]->ocupado == false){
            if(this->getX()/60 == 0 && this->getY()/60 == 1){
                qDebug()<<"No se pudo mover arriba, coincidia con el punto inicial";
            }
            else{
            Tablero::getInstance().cuadricula[this->getY()/60][this->getX()/60]->ocupado = false;
            this->setY(this->getY()-60);
            Tablero::getInstance().cuadricula[this->getY()/60][this->getX()/60]->ocupado = true;
            }
        }
        break;

    case 2:

        if((this->getX()/60) != 9 && Tablero::getInstance().cuadricula[(this->getY()/60)][this->getX()/60 +1]->ocupado == false){
            if(this->getX()/60 == 8 && this->getY()/60 == 9){
                qDebug()<<"No se pudo mover a la derecha, coincidia con el punto final";
            }
            else{
            Tablero::getInstance().cuadricula[this->getY()/60][this->getX()/60]->ocupado = false;
            this->setX(this->getX()+60);
            Tablero::getInstance().cuadricula[this->getY()/60][this->getX()/60]->ocupado = true;
            }
        }
        break;
    case 3:

        if(this->getY() / 60 != 9 && Tablero::getInstance().cuadricula[this->getY()/60 +1][this->getX()/60]->ocupado == false){
            if(this->getX()/60 == 9 && this->getY()/60 == 8){
                qDebug()<<"No se pudo mover a la abajo, coincidia con el punto final";
            }
            else{
            Tablero::getInstance().cuadricula[this->getY()/60][this->getX()/60]->ocupado = false;
            this->setY(this->getY()+60);
            Tablero::getInstance().cuadricula[this->getY()/60][this->getX()/60]->ocupado = true;
            }
        }
        break;
    case 4:
        if(this->getX() / 60 != 0 && Tablero::getInstance().cuadricula[this->getY()/60][this->getX()/60 -1]->ocupado == false){
            if(this->getX()/60 == 1 && this->getY()/60 == 0){
                qDebug()<<"No se pudo mover a la izquierda, coincidia con el punto inicial";
            }
            else{
            Tablero::getInstance().cuadricula[this->getY()/60][this->getX()/60]->ocupado = false;
            this->setX(this->getX()-60);
            Tablero::getInstance().cuadricula[this->getY()/60][this->getX()/60]->ocupado = true;
            }
        }
        break;
    }
    actualizarCuadrosAlcance();
}

