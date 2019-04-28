#include "lista.h"

Lista::Lista()
{

}

Nodo* Lista::getHead(){
    return this->Head;
}
int Lista::getcantidad(){
    return this->cantidad;
}
void Lista::agregarIinicio(Nodo *nuevoNodo){
   nuevoNodo->setSiguiente(Head);
   Head = nuevoNodo;
}

void Lista::agregarFinal(Nodo *nuevoNodo){
    Nodo *actual=Head;
    if(Head !=nullptr){
        while(actual->getSiguiente()!=nullptr){
            actual=actual->getSiguiente();
        }
        actual->setSiguiente(nuevoNodo);
    }

    else{
        Head = nuevoNodo;
        Head->setSiguiente(nullptr);
    }
}
void Lista::imprimir(){
    Nodo *actual = Head;
        if(actual==nullptr){
            cout<<"no hay elementos"<<endl;
        }

        else{
            while(actual->getSiguiente()!=nullptr){
                cout<<actual<<endl;
                actual=actual->getSiguiente();
            }
    }
}
Nodo* Lista::solicitar(Nodo *nodoBuscar){
    Nodo *actual = Head;
    if(actual==nullptr){
        cout<<"no hay elementos"<<endl;
    }
    else{
        while(actual->getSiguiente()!=nullptr){
            if(nodoBuscar==actual){
                return actual;
            }else {
                actual=actual->getSiguiente();
            }
        }
        cout<<"no se encontro elemento"<<endl;
    }
}
int Lista::random(){
    int r = rand() % 2;
    for (int i=0;i<6;i++) {
        r = rand() % 2;
        std::cout << " rnum: " << r;
    }
    std::cout << " termina " <<endl;
    return 1;
}
