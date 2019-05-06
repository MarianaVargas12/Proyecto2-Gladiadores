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
    string serializarTableroGladiador(int matrix[10][10], int edad, int emocional, int condicionFisica, int resistencia, int velocidad, int generacion, int id, int vida, int fitness, int probabilidad,
    int troncoSuperior, int troncoInferior, int supervivenciaGen);
    void DeserealizarPartida(string json, bool *play, int *turno, bool *mod3);
};

#endif // SERIALIZADOR_H
