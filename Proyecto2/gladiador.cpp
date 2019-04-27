#include "gladiador.h"

Gladiador::Gladiador(int id,int edad, int emocional, int condicionfisica, int troncoSuperior, int troncoinferiro, int velocidad, int generacion)
{
    this->id=id;
    this->edad=edad;
    this->emocional=emocional;
    this->condicionFisica=condicionfisica;
    this->troncoSuperior=troncoSuperior;
    this->troncoInferior=troncoinferiro;
    this->Velocidad=velocidad;
    this->generacion=generacion;
    resitencia();
    Probabilidad();
    GeneracionesSupervivencia();
}

void Gladiador::Probabilidad(){
    this->probabilidad=resistencia*22/100;
}
void Gladiador::GeneracionesSupervivencia(){
    this->supervivenciaGen= resistencia+edad;
}
void Gladiador::resitencia(){
    this->resistencia= emocional+condicionFisica*2+troncoSuperior*2+troncoInferior*2+Velocidad-edad*2;
    if(this->resistencia<0){
        this->resistencia=this->resistencia*(-1);
    }else if (this->resistencia==0) {
        this->resistencia=5;
    }else {

    }
}
