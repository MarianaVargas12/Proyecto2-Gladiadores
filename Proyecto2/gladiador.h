#ifndef GLADIADOR_H
#define GLADIADOR_H


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
    Gladiador(int vida,int id,int edad, int emocional,int condicionfisica, int troncoSuperior, int troncoinferiro, int velocidad, int generacion);
    void setProbabilidad(int maximaResistencia);
    void setGeneracionesSupervivencia();
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
    void setFitness();
};

#endif // GLADIADOR_H
