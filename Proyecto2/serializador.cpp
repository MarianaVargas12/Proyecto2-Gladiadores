#include "serializador.h"

serializador::serializador()
{

}

string serializador::serializarTableroGladiador(int matrix[10][10], int edad, int emocional,
int condicionFisica, int resistencia, int velocidad, int generacion, int id, int vida, int fitness, int probabilidad,
int troncoSuperior, int troncoInferior, int supervivenciaGen)
{
    const char* json = "{\"edad\":0,"
                       "\"emocional\":0,"
                       "\"condicionFisica\":0,"
                       "\"resistencia\":0,"
                       "\"velocidad\":0,"
                       "\"generacion\":0,"
                       "\"id\":0,"
                       "\"vida\":0,"
                       "\"matrix\":[[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0]],"
                       "\"probabilidad\":0,"
                       "\"troncoSuperior\":0,"
                       "\"troncoInferior\":0,"
                       "\"supervivenciaGen\":0,"
                       "\"fitness\":0}";
    Document d;
    d.Parse(json);
    d["edad"].SetInt(edad);
    d["emocional"].SetInt(emocional);
    d["condicionFisica"].SetInt(condicionFisica);
    d["resistencia"].SetInt(resistencia);
    d["velocidad"].SetInt(velocidad);
    d["generacion"].SetInt(generacion);
    d["id"].SetInt(id);
    d["vida"].SetInt(vida);
    d["fitness"].SetInt(fitness);
    d["probabilidad"].SetInt(probabilidad);
    d["troncoSuperior"].SetInt(troncoSuperior);
    d["troncoInferior"].SetInt(troncoInferior);
    d["supervivenciaGen"].SetInt(supervivenciaGen);
    for (int j=0;j<10;j++){
        for(int i=0; i<10;i++){
        d["matrix"].GetArray()[j][i]=matrix[j][i];
        }

    }
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    d.Accept(writer);
    qDebug()<<buffer.GetString();
    return buffer.GetString();

}
void serializador::DeserealizarPartida(string json,bool *play, int *turno, bool *mod3){
    Document d;
    d.Parse(json.c_str());
    *play =d["play"].GetBool();
    *turno= d["turno"].GetInt();
    *mod3 = d["mod3"].GetBool();
}


