#include "poblacion.h"

Poblacion::Poblacion()
{

}
void Poblacion::cruces(){
    if(mejores[0]->getCondicion()<mejores[1]->getCondicion()){
        datos[4]=mejores[1]->getCondicion();
        if(mejores[0]->getSuperior()<mejores[1]->getSuperior()){
            datos[5]=mejores[1]->getSuperior();
            if(mejores[0]->getVelocidad()<mejores[1]->getVelocidad()){
               datos[7]=mejores[1]->getVelocidad();
            }else{
                datos[7]=mejores[0]->getVelocidad();
            }
        }else {
            datos[5]=mejores[0]->getSuperior();
            if(mejores[0]->getVelocidad()<mejores[1]->getVelocidad()){
               datos[7]=mejores[1]->getVelocidad();
            }else{
                datos[7]=mejores[0]->getVelocidad();
            }
        }
    }else{
        datos[4]=mejores[0]->getCondicion();
        if(mejores[0]->getSuperior()<mejores[1]->getSuperior()){
            datos[5]=mejores[1]->getSuperior();
            if(mejores[0]->getVelocidad()<mejores[1]->getVelocidad()){
               datos[7]=mejores[1]->getVelocidad();
            }else{
                datos[7]=mejores[0]->getVelocidad();
            }
        }else {
            datos[5]=mejores[0]->getSuperior();
            if(mejores[0]->getVelocidad()<mejores[1]->getVelocidad()){
               datos[7]=mejores[1]->getVelocidad();
            }else{
                datos[7]=mejores[0]->getVelocidad();
            }
        }
    }
}
//agregar a la problacion
void Poblacion::insercion(Gladiador* nuevoGladiador){
    Nodo* nuevoNodo= new Nodo();
    nuevoNodo->setGladiador(nuevoGladiador);
    Gladiadores->agregarIinicio(nuevoNodo);
}
//mejor para reproducir
void Poblacion::seleccion(){
    Nodo* temp= Gladiadores->getHead();
    mejores[0]= temp->getGladiador();
    mejores[1]= temp->getSiguiente()->getGladiador();
    temp=temp->getSiguiente()->getSiguiente();
    while(temp!=nullptr){
        if(mejores[0]->getFitness()<temp->getGladiador()->getFitness()){
            mejores[0]=temp->getGladiador();
            temp= temp->getSiguiente();
        }else if (mejores[1]->getFitness()<temp->getGladiador()->getFitness()) {
            mejores[1]=temp->getGladiador();
            temp= temp->getSiguiente();
        }else{
            temp= temp->getSiguiente();
        }
    }

}
//variaciones aleatorias
void Poblacion::mutacion(){
    int randnum = (double)rand() / ((double)RAND_MAX + 2);
    int i=rand()%2 ;
    datos[i]=1;
    i=rand()%2 ;
    datos[2]=1;
    i=rand()%2 ;
    datos[3]=1;
    i=rand()%2 ;
    datos[6]=1;
    i=rand()%2 ;
    datos[8]=1;
}
void Poblacion::creacion(int cantidad){
    for (int i=0;i<cantidad;i++) {
        Gladiador* nuevoGladiador= new Gladiador(4,15,25,5,15,10,9,8,1);
        insercion(nuevoGladiador);
    }
}
