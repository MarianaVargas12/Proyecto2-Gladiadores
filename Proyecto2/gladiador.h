#ifndef GLADIADOR_H
#define GLADIADOR_H
#include <iostream>


class Gladiador
{
private:
    int edad;
    int probabilidad;
    int emocional;
    int condicionFisica;
    int troncoSuperior;
    int troncoInferior;
    int resistencia;
    int Velocidad;
    int generacion;
    int supervivenciaGen;
    int id;
    int vida;
    int fitness;
public:
    std::string atributos[10];
    int xgladiador;
    int ygladiador;
    Gladiador(int vida,int id,int edad, int emocional,int condicionfisica, int troncoSuperior, int troncoinferiro, int velocidad, int generacion);
    ///
    /// \brief segun el maximo fitness y el fitness del individuo
    /// \param maximoFitness
    ///
    void setProbabilidad();
    ///
    /// \brief segun la probabilidad se da la toma de supervivencia
    ///
    void setGeneracionesSupervivencia();
    ///
    /// \brief se da la resistencis usando una formula con ciertas caracteristicas
    ///
    void setresitencia();
    int getEdad();
    int getProbabilidad();
    int getEmocional();
    int getCondicion();
    int getSuperior();
    int getInferior();
    int getResistencia();
    int getVelocidad();
    int getGeneracion();
    int getSupervivncia();
    int getId();
    int getFitness();
    int getVida();
    void setvida(int vidaAnterior);
    ///
    /// \brief setFitness
    ///
    void setFitness();
};

#endif // GLADIADOR_H
