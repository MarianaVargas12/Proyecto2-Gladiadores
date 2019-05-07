#include "tablero.h"
#include "iostream"
using namespace std;

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
        if(xRand == 0 && yRand == 0){
            qDebug()<<"No se pudo generar la torre ya que coincidia con el punto de incio";
        }
        else if (xRand == 9 && yRand == 9) {
            qDebug()<<"No se pudo generar la torre ya que coincidia con el punto Final";
        }
        else{
            if(cuadricula[xRand][yRand]->ocupado == false){
                torre* torreRandom = new torre();
                torreRandom->setX(cuadricula[xRand][yRand]->getX());
                torreRandom->setY(cuadricula[xRand][yRand]->getY());
                torreRandom->actualizarCuadrosAlcance();
                cuadricula[xRand][yRand]->ocupado = true;
                cuadriculaInt[xRand][yRand] = torreRandom->tipo;
                listaTorres->Add(torreRandom);
            }
        }
    }
}

void Tablero::imprimirMatriz()
{
    for (int i = 0;i<10;i++) {
        cout<<""<<endl;
        for (int j = 0;j<10;j++) {
            if(Tablero::getInstance().cuadricula[i][j]->ocupado == true){
                for (Node* nodoTorre = Tablero::getInstance().listaTorres->getFirst(); nodoTorre != nullptr ; nodoTorre = nodoTorre->getNext()){
                    torre* TorrePrueba = (torre*)nodoTorre->getData();
                    if (TorrePrueba->getX() == Tablero::getInstance().cuadricula[i][j]->getX() && TorrePrueba->getY() == Tablero::getInstance().cuadricula[i][j]->getY()){
                        cout<<TorrePrueba->tipo<<",";
                    }
                }
            }
            else {
                cout<<"0"<<",";
            }
        }
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
        }else if (i==9 && j==9) {
            int imp=0;
            ruta[iruta][0]= 9;
            ruta[iruta][1]= 9;
            while(imp<=iruta){
                qDebug()<<" X: "<<ruta[imp][0]<<" Y: "<<ruta[imp][1];
                imp++;
            }
            return;
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
