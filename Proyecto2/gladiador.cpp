#include "gladiador.h"

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
}

void Gladiador::setProbabilidad(int maximaResistencia){
    this->probabilidad=resistencia*maximaResistencia/100;
    setGeneracionesSupervivencia();
}
void Gladiador::setGeneracionesSupervivencia(){
    if(probabilidad<25){
        this->supervivenciaGen= 1;
    }else if (probabilidad<50) {
        this->supervivenciaGen=3;
    }else if (probabilidad<75) {
        this->supervivenciaGen=4;
    }else {
        this->supervivenciaGen=6;
    }
}
void Gladiador::setresitencia(){
    this->resistencia= emocional+condicionFisica*2+troncoSuperior*2+troncoInferior*2+Velocidad-edad*2;
    if(this->resistencia<0){
        this->resistencia=this->resistencia*(-1);
    }else if (this->resistencia==0) {
        this->resistencia=5;
    }else {

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
