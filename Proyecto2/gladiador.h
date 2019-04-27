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
public:
    Gladiador(int id,int edad, int emocional, int condicionfisica, int troncoSuperior, int troncoinferiro, int velocidad, int generacion);
    void Probabilidad();
    void GeneracionesSupervivencia();
    void resitencia();
};

#endif // GLADIADOR_H
