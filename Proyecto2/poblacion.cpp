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
               datos[7]=mejores[0]->getVelocidad();
            }else{
                datos[7]=mejores[1]->getVelocidad();
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
               datos[7]=mejores[0]->getVelocidad();
            }else{
                datos[7]=mejores[1]->getVelocidad();
            }
        }else {
            datos[5]=mejores[0]->getSuperior();
            if(mejores[0]->getVelocidad()<mejores[1]->getVelocidad()){
               datos[7]=mejores[0]->getVelocidad();
            }else{
                datos[7]=mejores[1]->getVelocidad();
            }
        }
    }
    mutacion();
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
    cout<<"*************mejores***********************"<<endl;
    cout<<"gladiador: "<<mejores[0]<<"vida: "<<mejores[0]->getVida()<<"edad: "<<mejores[0]->getEdad()<<"emocional: "<<mejores[0]->getEmocional()<<"condicion: "<<mejores[0]->getCondicion()<<"superior: "<<mejores[0]->getSuperior()<<"inferior: "<<mejores[0]->getInferior()<<"fitness: "<<mejores[0]->getFitness()<<endl;
    cout<<"gladiador: "<<mejores[1]<<"vida: "<<mejores[1]->getVida()<<"edad: "<<mejores[1]->getEdad()<<"emocional: "<<mejores[1]->getEmocional()<<"condicion: "<<mejores[1]->getCondicion()<<"superior: "<<mejores[1]->getSuperior()<<"inferior: "<<mejores[1]->getInferior()<<"fitness: "<<mejores[1]->getFitness()<<endl;

}
//variaciones aleatorias
void Poblacion::mutacion(){
    int i=rand()%2 ;
    datos[1]=mejores[i]->getVida();
    //i=rand()%2 ;
    datos[2]= 10;
    i=rand()%2 ;
    datos[3]=mejores[i]->getEdad();
    i=rand()%2 ;
    datos[6]=mejores[i]->getInferior();
    i=rand()%2 ;
    datos[8]=mejores[i]->getGeneracion();
}
void Poblacion::creacion(int cantidad){
    cruces();
    cout<<"*****************NuevaGeneracion************************"<<endl;

    for (int i=0;i<cantidad;i++) {
        int vida=(1+(rand()%(datos[0]+2)));
        //crear id
        int id=(1+(rand()%(datos[1])));
        int edad=(1+(rand()%(datos[2]+10)));
        int emocional=(1+(rand()%(datos[3]+5)));
        int condicion=(1+(rand()%(datos[4]+5)));
        int superior=(1+(rand()%(datos[5]+5)));
        int inferior=(1+(rand()%(datos[6]+5)));
        int velocidad=(1+(rand()%(datos[7]-5)));
        int generacion=this->generacion+1;
        this->generacion=generacion;
        int fitness= (datos[7]-5)+(datos[4]+5)+(datos[5]+5)+(datos[6]+5)-(datos[2]+10);
        Gladiador* nuevoGladiador= new Gladiador(vida,id,edad,emocional,condicion,superior,inferior,velocidad,generacion);
        nuevoGladiador->setProbabilidad(fitness);
        cout<<"gladiador: "<<nuevoGladiador<<"vida: "<<nuevoGladiador->getVida()<<"edad: "<<nuevoGladiador->getEdad()<<"emocional: "<<nuevoGladiador->getEmocional()<<"condicion: "<<nuevoGladiador->getCondicion()<<"superior: "<<nuevoGladiador->getSuperior()<<"inferior: "<<nuevoGladiador->getInferior()<<"fitness: "<<nuevoGladiador->getFitness()<<endl;
        insercion(nuevoGladiador);
    }
}
void Poblacion::poblacionInicial(int cantidad){
    for (int i=0;i<cantidad;i++) {
        int vida=(1+rand()%3);
        //crear id
        int id=1;
        int edad=(1+rand()%20);
        int emocional=(1+rand()%10);
        int condicion=(1+rand()%10);
        int superior=(1+rand()%10);
        int inferior=(1+rand()%10);
        int velocidad=(1+rand()%10);
        int generacion=1;
        this->generacion=1;
        Gladiador* nuevoGladiador= new Gladiador(vida,id,edad,emocional,condicion,superior,inferior,velocidad,generacion);
        cout<<"gladiador: "<<nuevoGladiador<<"vida: "<<nuevoGladiador->getVida()<<"edad: "<<nuevoGladiador->getEdad()<<"emocional: "<<nuevoGladiador->getEmocional()<<"condicion: "<<nuevoGladiador->getCondicion()<<"superior: "<<nuevoGladiador->getSuperior()<<"inferior: "<<nuevoGladiador->getInferior()<<"fitness: "<<nuevoGladiador->getFitness()<<endl;
        insercion(nuevoGladiador);
    }
}
