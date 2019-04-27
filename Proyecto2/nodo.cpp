#include "nodo.h"

Nodo::Nodo()
{

}

void Nodo::setSiguiente(Nodo* siguiente){
    this->siguiente=siguiente;
}
Nodo* Nodo::getSiguiente(){
    return this->siguiente;
}
void Nodo::setAnterior(Nodo* anterior){
    this->anterior=anterior;
}
Nodo* Nodo::getAnterior(){
    return this->anterior;
}
void Nodo::setAbajo(Nodo* abajo){
    this->abajo=abajo;
}
Nodo* Nodo::getAbajo(){
    return this->abajo;
}
void Nodo::setArriba(Nodo* arriba){
    this->arriba=arriba;
}
Nodo* Nodo::getArriba(){
    return this->arriba;
}
void Nodo::setOcupadoObstaculo(bool ocupado){
    this->ocupadoObstaculo=ocupado;
}
bool Nodo::getOcupadoObstaculo(){
    return this->ocupadoObstaculo;
}
void Nodo::setObstaculo(Obstaculo* obstaculo){
    this->obstaculo=obstaculo;
}
Obstaculo* Nodo::getObstaculo(){
    return this->obstaculo;
}
void Nodo::setOcupadoGladiador(bool ocupado){
    this->ocupadoGladiador=ocupado;
}
bool Nodo::getOcupadoGladiador(){
    return this->ocupadoGladiador;
}
void Nodo::setGladiador(Gladiador* gladiador){
    this->gladiador=gladiador;
}
Gladiador* Nodo::getGladiador(){
    return this->gladiador;
}
