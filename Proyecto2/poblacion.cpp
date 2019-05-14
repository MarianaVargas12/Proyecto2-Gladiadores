#include "poblacion.h"
#include <math.h>
Poblacion::Poblacion()
{

}
int* Poblacion::dectobin(int num){
    int* bin= new int[8];
    int i=7;
    while(i>=0){
        bin[i]=num%2;
        num=num/2;
        i--;
    }
    return bin;
}
int Poblacion::bintodec(int bin[8]){
    int i=7;
    int num=0;
    while(i>=0){
        if(bin[i]==1){
            num+=pow(2,i);
            i--;
        }else {
            i--;
        }
    }
    return num;
}

void Poblacion::cruces(){
    int* vida1=dectobin(mejores[0]->getVida());
    int* vida=dectobin(mejores[1]->getVida());
    int* emocional1=dectobin(mejores[0]->getEmocional());
    int* emocional2=dectobin(mejores[1]->getEmocional());
    int* condicionFisica1=dectobin(mejores[0]->getCondicion());
    int* condicionFisica2=dectobin(mejores[1]->getCondicion());
    int* troncoSup1=dectobin(mejores[0]->getSuperior());
    int* troncoSup2=dectobin(mejores[1]->getSuperior());
    int* troncoInf1=dectobin(mejores[0]->getInferior());
    int* troncoInf2=dectobin(mejores[1]->getInferior());
    int* velocidad1=dectobin(mejores[0]->getVelocidad());
    int* velocidad2=dectobin(mejores[1]->getVelocidad());
    int i=0;
    int padre=0;
    while (i<6) {
        padre = rand()%2;
        if(padre==0){
            datos[0][i]=vida1[i];
            datos[1][i]=emocional1[i];
            datos[2][i]=condicionFisica1[i];
            datos[3][i]=troncoSup1[i];
            datos[4][i]=troncoInf1[i];
            datos[5][i]=velocidad1[i];
            i++;
        }else {
            datos[0][i]=vida[i];
            datos[1][i]=emocional2[i];
            datos[2][i]=condicionFisica2[i];
            datos[3][i]=troncoSup2[i];
            datos[4][i]=troncoInf2[i];
            datos[5][i]=velocidad2[i];
            i++;
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
    cout<<"*************mejores***********************"<<endl;
    cout<<"gladiador: "<<mejores[0]<<"vida: "<<mejores[0]->getVida()<<"edad: "<<mejores[0]->getEdad()<<"emocional: "<<mejores[0]->getEmocional()<<"condicion: "<<mejores[0]->getCondicion()<<"superior: "<<mejores[0]->getSuperior()<<"inferior: "<<mejores[0]->getInferior()<<"fitness: "<<mejores[0]->getFitness()<<endl;
    cout<<"gladiador: "<<mejores[1]<<"vida: "<<mejores[1]->getVida()<<"edad: "<<mejores[1]->getEdad()<<"emocional: "<<mejores[1]->getEmocional()<<"condicion: "<<mejores[1]->getCondicion()<<"superior: "<<mejores[1]->getSuperior()<<"inferior: "<<mejores[1]->getInferior()<<"fitness: "<<mejores[1]->getFitness()<<endl;

}

Gladiador* Poblacion::mejor(){
    Nodo* temp= Gladiadores->getHead();
    Gladiador* mejor= temp->getGladiador();
    temp=temp->getSiguiente();
    while(temp!=nullptr){
        if(mejor->getFitness()<temp->getGladiador()->getFitness()){
            mejor=temp->getGladiador();
            temp= temp->getSiguiente();
        }else{
            temp= temp->getSiguiente();
        }
    }
    return mejor;
}
void Poblacion::mutacion(){
    int i=0;
    int j=0;
    while (i<6) {
        while(j<8){
            if(datos[i][j]==0){
                datos[i][j]=1;
                j++;
            }else {
                datos[i][j]=0;
                j++;
            }
        }
        j=0;
        i++;
    }
}

//variaciones aleatorias
void Poblacion::inversion(){
    int num=rand()%8 ;
    int i=0;
    while(i<6){
        num=rand()%8 ;
        datos[i][num]=1;
    }

}
void Poblacion::creacion(int cantidad){
    seleccion();
    int transfromar=0;
    cout<<"*****************NuevaGeneracion************************"<<endl;
    for (int i=0;i<cantidad;i++) {

        transfromar = rand()%3;
        cruces();
        if(transfromar==0){
            mutacion();
        }else if (transfromar==1) {
            inversion();
        }
        int vida=bintodec(datos[0]);
        //crear id y edad
        int id=123;
        int edad= 4;
        int emocional=bintodec(datos[1]);
        int condicion=bintodec(datos[2]);
        int superior=bintodec(datos[3]);
        int inferior=bintodec(datos[4]);
        int velocidad=bintodec(datos[5]);
        int generacion=this->generacion+1;
        Gladiador* nuevoGladiador= new Gladiador(vida,id,edad,emocional,condicion,superior,inferior,velocidad,generacion);
        int fitness= velocidad+condicion+superior+inferior;
        if(fitness>=this->fitness){
            this->fitness=fitness;
        }
        nuevoGladiador->setProbabilidad(this->fitness);
        cout<<"gladiador: "<<nuevoGladiador<<"vida: "<<nuevoGladiador->getVida()<<"edad: "<<nuevoGladiador->getEdad()<<"emocional: "<<nuevoGladiador->getEmocional()<<"condicion: "<<nuevoGladiador->getCondicion()<<"superior: "<<nuevoGladiador->getSuperior()<<"inferior: "<<nuevoGladiador->getInferior()<<"fitness: "<<nuevoGladiador->getFitness()<<endl;
        insercion(nuevoGladiador);
    }
    this->generacion=generacion+1;
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
