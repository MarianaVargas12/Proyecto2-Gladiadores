#include "poblacion.h"
#include <math.h>
#include "iostream"
using namespace std;
Poblacion::Poblacion()
{

}

void Poblacion::Grafico(){
    Nodo* temp= Gladiadores->getHead();
    Gladiador* mejor= temp->getGladiador();
    temp=temp->getSiguiente();
    int i=0;
    cout<<"********holiii******"<<endl;
    while(temp!=nullptr){
        if(temp->getGladiador()->getGeneracion()==this->generacion){
            mejor=temp->getGladiador();
            i+=mejor->getFitness();
            temp= temp->getSiguiente();
        }else{
            temp= temp->getSiguiente();
        }
    }
    cout<<i<<endl;
    i=i/5;
    this->grafico+=std::to_string(i)+",";
    cout<<this->grafico<<endl;
}
string Poblacion::getGrafico(){
    return this->grafico;
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
    int padre;
    while (i<6) {
        padre = rand()%2;
        if(padre==0){
            datos[1][i]=emocional1[i];
            datos[2][i]=condicionFisica1[i];
            datos[3][i]=troncoSup1[i];
            datos[4][i]=troncoInf1[i];
            datos[5][i]=velocidad1[i];
            i++;
        }else {
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
void Poblacion::inversion(){
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
void Poblacion::mutacion(){
    int num;
    int i=0;
    while(i<6){
        num=rand()%8 ;
        datos[i][num]=1;
        i++;
    }

}
void Poblacion::creacion(int cantidad){
    seleccion();
    int transfromar;
    this->generacion=this->generacion+1;
    for (int i=0;i<cantidad;i++) {
        int num = rand()%30;;
        transfromar = num;
        cruces();
        if(transfromar==0){
            mutacion();
        }else if (transfromar==1) {
            inversion();
        }
        //crear id y edad
        int id=rand()%3000;;
        int edad= 4;
        int emocional=bintodec(datos[1]);
        int condicion=bintodec(datos[2]);
        int superior=bintodec(datos[3]);
        int inferior=bintodec(datos[4]);
        int velocidad=bintodec(datos[5]);
        int generacion=this->generacion;
        Gladiador* nuevoGladiador= new Gladiador(mejores[0]->getVida(),id,edad,emocional,condicion,superior,inferior,velocidad,generacion);
        int mejor = rand()%2;;
        nuevoGladiador->setvida(mejores[mejor]->getVida());
        insercion(nuevoGladiador);
    }
    Grafico();
}
void Poblacion::poblacionInicial(int cantidad){
    for (int i=0;i<cantidad;i++) {
        int vida=2;
        int id=rand()%3000;;
        int edad=(rand()%20 +1);
        int emocional=(rand()%10 +1);
        int condicion=(rand()%10 +1);
        int superior=(rand()%10 +1);
        int inferior=(rand()%10 +1);
        int velocidad=(rand()%10 +1);
        int generacion=0;
        this->generacion=0;
        Gladiador* nuevoGladiador= new Gladiador(vida,id,edad,emocional,condicion,superior,inferior,velocidad,generacion);
        insercion(nuevoGladiador);
    }
    Grafico();
}
