#include "gladiador.h"
#include <iostream>

Gladiador::Gladiador(int vida,int id,int edad, int emocional, int condicionfisica, int troncoSuperior, int troncoinferiro, int velocidad, int generacion)
{
    this->id=id;
    this->edad=edad;
    this->emocional=emocional;
    this->condicionFisica=condicionfisica;
    this->troncoSuperior=troncoSuperior;
    this->troncoInferior=troncoinferiro;
    this->Velocidad=velocidad;
    this->generacion=generacion;
    this->vida=vida;
    setresitencia();
    setFitness();
    setProbabilidad();
}

void Gladiador::setProbabilidad(){
    this->probabilidad=this->fitness*100/1020;
    setGeneracionesSupervivencia();
}
void Gladiador::setGeneracionesSupervivencia(){
    if(probabilidad<35){
        this->supervivenciaGen= 1;
    }else if (probabilidad<55) {
        this->supervivenciaGen=3;
    }else if (probabilidad<70) {
        this->supervivenciaGen=4;
    }else {
        this->supervivenciaGen=6;
    }
}
void Gladiador::setvida(int vidaAnterior){
    if(probabilidad<10){
        this->vida= vidaAnterior+1;
    }else if (probabilidad<20) {
        this->vida= vidaAnterior+2;
    }else if (probabilidad<30) {
        this->vida= vidaAnterior+3;
    }else if (probabilidad<40) {
        this->vida= vidaAnterior+4;
    }else if (probabilidad<50) {
        this->vida= vidaAnterior+5;
    }else if (probabilidad<60) {
        this->vida= vidaAnterior+6;
    }else if (probabilidad<70) {
        this->vida= vidaAnterior+7;
    }else if (probabilidad<80) {
        this->vida= vidaAnterior+8;
    }else if (probabilidad<90) {
        this->vida= vidaAnterior+9;
    }else {
        this->vida= vidaAnterior+10;
    }
}
void Gladiador::setresitencia(){
    this->resistencia= emocional+condicionFisica*2+troncoSuperior*2+troncoInferior*2+Velocidad-edad*2;
    if(this->resistencia<0){
        this->resistencia=this->resistencia*(-1);
    }else if (this->resistencia==0) {
        this->resistencia=5;
    }
}
int Gladiador::getEdad(){
    return this->edad;
}
int Gladiador::getProbabilidad(){
    return this->probabilidad;
}
int Gladiador::getEmocional(){
    return this->emocional;
}
int Gladiador::getCondicion(){
    return this->condicionFisica;
}
int Gladiador::getSuperior(){
    return this->troncoSuperior;
}
int Gladiador::getInferior(){
    return this->troncoInferior;
}
int Gladiador::getResistencia(){
    return this->resistencia;
}
int Gladiador::getVelocidad(){
    return this->Velocidad;
}
int Gladiador::getGeneracion(){
    return this->generacion;
}
int Gladiador::getSupervivncia(){
    return this->supervivenciaGen;
}
int Gladiador::getId(){
    return this->id;
}
int Gladiador::getFitness(){
    return this->fitness;
}
int Gladiador::getVida(){
    return this->vida;
}
void Gladiador::setFitness(){
    this->fitness= Velocidad+condicionFisica+troncoSuperior+troncoInferior;
}
