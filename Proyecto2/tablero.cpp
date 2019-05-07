#include "tablero.h"

Tablero::Tablero()
{
    int xInicial = 0;
    int yInicial = 0;
    for (int i = 0; i < 10;i++) {
        for (int j = 0; j < 10;j++) {
            cuadro* nuevoCuadro = new cuadro();
            nuevoCuadro->setX(xInicial);
            nuevoCuadro->setY(yInicial);
            cuadricula[i][j] = nuevoCuadro;
            yInicial+=60;
        }
        yInicial = 0;
        xInicial+= 60;

    }
}


void Tablero::generarTorre()
{

    int xRand = rand()%10;
    int yRand = rand()%10;
    if(xRand != 0 && yRand != 0 || xRand != 9 && yRand !=9){
        if(cuadricula[xRand][yRand]->ocupado == false){
            torre* torreRandom = new torre();
            torreRandom->setX(cuadricula[xRand][yRand]->getX());
            torreRandom->setY(cuadricula[xRand][yRand]->getY());
            torreRandom->actualizarCuadrosAlcance();
            cuadricula[xRand][yRand]->ocupado = true;
            listaTorres->Add(torreRandom);
        }
    }
    else {
        qDebug()<<"No se pudo generar la torre ya que coincidia con el punto de incio o el final";
    }
}

void Tablero::backtracking(){
    int j=0;
    int i=0;
    LinkedList* listaAnteriores= new LinkedList();
    int ivisitados=0;
    int iruta=0;
    int ruta[100][2];
    int visitados[100][2];
    while(0<=i<10 && 0<=j<10){
        if(i-1<0 && j-1<0){
            if(Tablero::getInstance().cuadricula[i+1][j+1]->ocupado == false && visitado(i+1,j+1,ivisitados,visitados)){
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i+=1;
                j+=1;
            }else if (Tablero::getInstance().cuadricula[i+1][j]->ocupado == false && visitado(i+1,j, ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i+=1;
            }else if (Tablero::getInstance().cuadricula[i][j+1]->ocupado == false && visitado(i,j+1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                j+=1;
            }else {
                visitados[ivisitados][0]=ruta[iruta-1][0];
                visitados[ivisitados][1]=ruta[iruta-1][1];
                iruta-=1;
                ivisitados+=1;
                Node* nuevo= listaAnteriores->removeLast();
                i=*(int*)nuevo->getData();
                j=*((int*)nuevo->getData()+1);
            }
        }else if (i+1>=10 && j-1<0) {
            if(Tablero::getInstance().cuadricula[i][j+1]->ocupado == false && visitado(i,j+1,ivisitados,visitados)){
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                j+=1;
            }else if (Tablero::getInstance().cuadricula[i-1][j+1]->ocupado == false && visitado(i-1,j+1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i-=1;
                j+=1;
            }else if (Tablero::getInstance().cuadricula[i-1][j]->ocupado == false && visitado(i-1,j,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i-=1;
            }else {
                visitados[ivisitados][0]=ruta[iruta-1][0];
                visitados[ivisitados][1]=ruta[iruta-1][1];
                iruta-=1;
                ivisitados+=1;
                Node* nuevo= listaAnteriores->removeLast();
                i=*(int*)nuevo->getData();
                j=*((int*)nuevo->getData()+1);
            }
        }else if (i-1<0 && j+1>=10) {
            if(Tablero::getInstance().cuadricula[i+1][j]->ocupado == false && visitado(i+1,j,ivisitados,visitados)){
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i+=1;
            }else if (Tablero::getInstance().cuadricula[i+1][j-1]->ocupado == false && visitado(i+1,j-1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i+=1;
                j-=1;
            }else if (Tablero::getInstance().cuadricula[i][j-1]->ocupado == false && visitado(i,j-1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                j-=1;
            }else {
                visitados[ivisitados][0]=ruta[iruta-1][0];
                visitados[ivisitados][1]=ruta[iruta-1][1];
                iruta-=1;
                ivisitados+=1;
                Node* nuevo= listaAnteriores->removeLast();
                i=*(int*)nuevo->getData();
                j=*((int*)nuevo->getData()+1);
            }
        }else if (i+1>=10 && j+1>=10) {
            //return ruta;
        }else if (i-1<0) {
            if(Tablero::getInstance().cuadricula[i+1][j+1]->ocupado == false && visitado(i+1,j+1,ivisitados,visitados)){
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i+=1;
                j+=1;
            }else if (Tablero::getInstance().cuadricula[i+1][j]->ocupado == false && visitado(i+1,j,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i+=1;
            }else if (Tablero::getInstance().cuadricula[i][j+1]->ocupado == false && visitado(i,j+1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                j+=1;
            }else if (Tablero::getInstance().cuadricula[i+1][j-1]->ocupado == false && visitado(i+1,j-1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i+=1;
                j-=1;
            }else if (Tablero::getInstance().cuadricula[i][j-1]->ocupado == false && visitado(i,j-1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                j-=1;
            }else {
                visitados[ivisitados][0]=ruta[iruta-1][0];
                visitados[ivisitados][1]=ruta[iruta-1][1];
                iruta-=1;
                ivisitados+=1;
                Node* nuevo= listaAnteriores->removeLast();
                i=*(int*)nuevo->getData();
                j=*((int*)nuevo->getData()+1);
            }
        }else if (j-1<0) {
            if(Tablero::getInstance().cuadricula[i+1][j+1]->ocupado == false && visitado(i+1,j+1,ivisitados,visitados)){
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i+=1;
                j+=1;
            }else if (Tablero::getInstance().cuadricula[i+1][j]->ocupado == false && visitado(i+1,j,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i+=1;
            }else if (Tablero::getInstance().cuadricula[i][j+1]->ocupado == false && visitado(i,j+1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                j+=1;
            }else if (Tablero::getInstance().cuadricula[i-1][j+1]->ocupado == false && visitado(i-1,j+1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i-=1;
                j+=1;
            }else if (Tablero::getInstance().cuadricula[i-1][j]->ocupado == false && visitado(i-1,j,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i-=1;
            }else {
                visitados[ivisitados][0]=ruta[iruta-1][0];
                visitados[ivisitados][1]=ruta[iruta-1][1];
                iruta-=1;
                ivisitados+=1;
                Node* nuevo= listaAnteriores->removeLast();
                i=*(int*)nuevo->getData();
                j=*((int*)nuevo->getData()+1);
            }
        }else if (j+1>=10) {
            if(Tablero::getInstance().cuadricula[i+1][j]->ocupado == false && visitado(i+1,j,ivisitados,visitados)){
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i+=1;
            }else if (Tablero::getInstance().cuadricula[i+1][j-1]->ocupado == false && visitado(i+1,j-1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i+=1;
                j-=1;
            }else if (Tablero::getInstance().cuadricula[i][j-1]->ocupado == false && visitado(i,j-1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                j-=1;
            }else if (Tablero::getInstance().cuadricula[i-1][j]->ocupado == false && visitado(i-1,j,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i-=1;
            }else if (Tablero::getInstance().cuadricula[i-1][j-1]->ocupado == false && visitado(i-1,j-1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i-=1;
                j-=1;
            }else {
                visitados[ivisitados][0]=ruta[iruta-1][0];
                visitados[ivisitados][1]=ruta[iruta-1][1];
                iruta-=1;
                ivisitados+=1;
                Node* nuevo= listaAnteriores->removeLast();
                i=*(int*)nuevo->getData();
                j=*((int*)nuevo->getData()+1);
            }
        }else if (i+1>=10) {
            if(Tablero::getInstance().cuadricula[i][j+1]->ocupado == false && visitado(i,j+1,ivisitados,visitados)){
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                j+=1;
            }else if (Tablero::getInstance().cuadricula[i-1][j+1]->ocupado == false && visitado(i-1,j+1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i-=1;
                j+=1;
            }else if (Tablero::getInstance().cuadricula[i-1][j]->ocupado == false && visitado(i-1,j,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i-=1;
            }else if (Tablero::getInstance().cuadricula[i][j-1]->ocupado == false && visitado(i,j-1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                j-=1;
            }else if (Tablero::getInstance().cuadricula[i-1][j-1]->ocupado == false && visitado(i-1,j-1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i-=1;
                j-=1;
            }else {
                visitados[ivisitados][0]=ruta[iruta-1][0];
                visitados[ivisitados][1]=ruta[iruta-1][1];
                iruta-=1;
                ivisitados+=1;
                Node* nuevo= listaAnteriores->removeLast();
                i=*(int*)nuevo->getData();
                j=*((int*)nuevo->getData()+1);
            }
        }else {
            if(Tablero::getInstance().cuadricula[i+1][j+1]->ocupado == false && visitado(i+1,j+1,ivisitados,visitados)){
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i+=1;
                j+=1;
            }else if (Tablero::getInstance().cuadricula[i][j+1]->ocupado == false && visitado(i,j+1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                j+=1;
            }else if (Tablero::getInstance().cuadricula[i+1][j]->ocupado == false && visitado(i+1,j,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i+=1;
            }else if (Tablero::getInstance().cuadricula[i-1][j+1]->ocupado == false && visitado(i-1,j+1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i-=1;
                j+=1;
            }else if (Tablero::getInstance().cuadricula[i+1][j-1]->ocupado == false && visitado(i+1,j-1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i+=1;
                j-=1;
            }else if (Tablero::getInstance().cuadricula[i][j-1]->ocupado == false && visitado(i,j-1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                j-=1;
            }else if (Tablero::getInstance().cuadricula[i-1][j]->ocupado == false && visitado(i-1,j,iruta,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i-=1;
            }else if (Tablero::getInstance().cuadricula[i-1][j-1]->ocupado == false&& visitado(i-1,j-1,ivisitados,visitados)) {
                ruta[iruta][0]= i;
                ruta[iruta][1]= j;
                int anteriorArray[2];
                anteriorArray[0]=i;
                anteriorArray[1]=j;
                listaAnteriores->Add(anteriorArray);
                iruta+=1;
                i-=1;
                j-=1;
            }else {
                visitados[ivisitados][0]=ruta[iruta-1][0];
                visitados[ivisitados][1]=ruta[iruta-1][1];
                iruta-=1;
                ivisitados+=1;
                Node* nuevo= listaAnteriores->removeLast();
                i=*(int*)nuevo->getData();
                j=*((int*)nuevo->getData()+1);
            }
        }
   }
}
bool Tablero::visitado(int i, int j, int max,int visitados[][2]){
    int x=0;
    while(x<=max){
        if(visitados[x][0]==i && visitados[x][1]==j){
            return false;
        }
        x++;
    }
    return true;
}
