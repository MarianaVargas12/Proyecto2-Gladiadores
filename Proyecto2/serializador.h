#include "QDebug"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#define PORT 8080
using namespace std;
using namespace rapidjson;
#ifndef SERIALIZADOR_H
#define SERIALIZADOR_H


class serializador
{
public:
    /**
     * @brief
     *
     */
    serializador();
    string serializarGeneracion();
    static serializador & getInstance(){
        static serializador instance;
        return instance;
    }
    void DeserealizarPartida(string json, bool *play, int *turno, bool *mod3);
    string serializarTableroGladiador(int matrix[10][10], int edad, int edadBack, int emocional, int emocionalBack, int condicionFisica, int condicionFisicaBack, int resistencia, int resistenciaBack, int velocidad, int velocidadBack, int generacion, int generacionBack, int id, int idBack, int vida, int vidaBack, int fitness, int fitnessBack, int probabilidad, int ptobabilidadBack, int troncoSuperior, int troncoSuperiorBack, int troncoInferior, int troncoInferiorBack, int supervivenciaGen, int supervivenciaGenBack, int** aStar, int** backTrack);
    string serializarIteracion3(int matrix[10][10], int edad, int edadBack, int emocional, int emocionalBack,
    int condicionFisica,int condicionFisicaBack, int resistencia, int resistenciaBack, int velocidad, int velocidadBack, int generacion, int generacionBack, int id, int idBack, int vida, int vidaBack, int fitness, int fitnessBack, int probabilidad, int probabilidadBack,
    int troncoSuperior, int troncoSuperiorBack, int troncoInferior, int troncoInferiorBack, int supervivenciaGen, int supervivenciaGenBack, int** aStar, int** backTrack, int ubicacion[2]);
    string serializarGrafico(string grafico1, string grafico2);
};

#endif // SERIALIZADOR_H
