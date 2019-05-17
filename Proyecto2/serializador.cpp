#include "serializador.h"

serializador::serializador()
{

}
string serializador::serializarIteracion3(int matrix[10][10], int edad, int edadBack, int emocional, int emocionalBack,
int condicionFisica,int condicionFisicaBack, int resistencia, int resistenciaBack, int velocidad, int velocidadBack, int generacion, int generacionBack, int id, int idBack, int vida, int vidaBack, int fitness, int fitnessBack, int probabilidad, int probabilidadBack,
int troncoSuperior, int troncoSuperiorBack, int troncoInferior, int troncoInferiorBack, int supervivenciaGen, int supervivenciaGenBack, int** aStar, int** backTrack, int ubicacion[2])
{
    const char* json = "{\"edad\":[0,0],"
                       "\"emocional\":[0,0],"
                       "\"condicionFisica\":[0,0],"
                       "\"resistencia\":[0,0],"
                       "\"velocidad\":[0,0],"
                       "\"generacion\":[0,0],"
                       "\"id\":[0,0],"
                       "\"vida\":[0,0],"
                       "\"matrix\":[[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0]],"
                       "\"probabilidad\":[0,0],"
                       "\"aStar\":[[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0]],"
                       "\"backTrack\":[[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0]],"
                       "\"troncoSuperior\":[0,0],"
                       "\"troncoInferior\":[0,0],"
                       "\"supervivenciaGen\":[0,0],"
                       "\"ubicacion\":[0,0],"
                       "\"fitness\":[0,0]}";
    Document d;
    d.Parse(json);
    d["edad"].GetArray()[0]=edad;
    d["edad"].GetArray()[1]=edadBack;
    d["emocional"].GetArray()[0]=emocional;
    d["emocional"].GetArray()[1]=emocionalBack;
    d["condicionFisica"].GetArray()[0]=condicionFisica;
    d["condicionFisica"].GetArray()[1]=condicionFisicaBack;
    d["resistencia"].GetArray()[0]=resistencia;
    d["resistencia"].GetArray()[1]=resistenciaBack;
    d["velocidad"].GetArray()[0]=velocidad;
    d["velocidad"].GetArray()[1]=velocidadBack;
    d["generacion"].GetArray()[0]=generacion;
    d["generacion"].GetArray()[1]=generacionBack;
    d["id"].GetArray()[0]=id;
    d["id"].GetArray()[1]=idBack;
    d["vida"].GetArray()[0]=vida;
    d["vida"].GetArray()[1]=vidaBack;
    d["fitness"].GetArray()[0]=fitness;
    d["fitness"].GetArray()[1]=fitnessBack;
    d["probabilidad"].GetArray()[0]=probabilidad;
    d["probabilidad"].GetArray()[1]=probabilidadBack;
    d["troncoSuperior"].GetArray()[0]=troncoSuperior;
    d["troncoSuperior"].GetArray()[1]=troncoSuperiorBack;
    d["troncoInferior"].GetArray()[0]=troncoInferior;
    d["troncoInferior"].GetArray()[1]=troncoInferiorBack;
    d["supervivenciaGen"].GetArray()[0]=supervivenciaGen;
    d["supervivenciaGen"].GetArray()[1]=supervivenciaGenBack;
    for (int j=0;j<10;j++){
        for(int i=0; i<10;i++){
        d["matrix"].GetArray()[j][i]=matrix[j][i];
        }

    }
    for (int j=0;j<30;j++){
        if(aStar[j][0]==9 and aStar[j][1]==9){
            d["aStar"].GetArray()[j][0]=aStar[j][0];
            d["aStar"].GetArray()[j][1]=aStar[j][1];
            break;
        }
        else{
            d["aStar"].GetArray()[j][0]=aStar[j][0];
            d["aStar"].GetArray()[j][1]=aStar[j][1];
        }

    }
    for (int j=0;j<30;j++){
        if(backTrack[j][0]==9 and backTrack[j][1]==9){
            d["backTrack"].GetArray()[j][0]=backTrack[j][0];
            d["backTrack"].GetArray()[j][1]=backTrack[j][1];
            break;
        }
        else{
            d["backTrack"].GetArray()[j][0]=backTrack[j][0];
            d["backTrack"].GetArray()[j][1]=backTrack[j][1];
        }

    }
   d["ubicacion"].GetArray()[0]=ubicacion[0];
   d["ubicacion"].GetArray()[1]=ubicacion[1];
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    d.Accept(writer);
    qDebug()<<buffer.GetString();
    return buffer.GetString();

}
string serializador::serializarTableroGladiador(int matrix[10][10], int edad, int edadBack, int emocional, int emocionalBack,
int condicionFisica,int condicionFisicaBack, int resistencia, int resistenciaBack, int velocidad, int velocidadBack, int generacion, int generacionBack, int id, int idBack, int vida, int vidaBack, int fitness, int fitnessBack, int probabilidad, int probabilidadBack,
int troncoSuperior, int troncoSuperiorBack, int troncoInferior, int troncoInferiorBack, int supervivenciaGen, int supervivenciaGenBack, int** aStar, int** backTrack)
{
    const char* json = "{\"edad\":[0,0],"
                       "\"emocional\":[0,0],"
                       "\"condicionFisica\":[0,0],"
                       "\"resistencia\":[0,0],"
                       "\"velocidad\":[0,0],"
                       "\"generacion\":[0,0],"
                       "\"id\":[0,0],"
                       "\"vida\":[0,0],"
                       "\"matrix\":[[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0]],"
                       "\"probabilidad\":[0,0],"
                       "\"aStar\":[[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0]],"
                       "\"backTrack\":[[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0]],"
                       "\"troncoSuperior\":[0,0],"
                       "\"troncoInferior\":[0,0],"
                       "\"supervivenciaGen\":[0,0],"
                       "\"fitness\":[0,0]}";
    Document d;
    d.Parse(json);
    d["edad"].GetArray()[0]=edad;
    d["edad"].GetArray()[1]=edadBack;
    d["emocional"].GetArray()[0]=emocional;
    d["emocional"].GetArray()[1]=emocionalBack;
    d["condicionFisica"].GetArray()[0]=condicionFisica;
    d["condicionFisica"].GetArray()[1]=condicionFisicaBack;
    d["resistencia"].GetArray()[0]=resistencia;
    d["resistencia"].GetArray()[1]=resistenciaBack;
    d["velocidad"].GetArray()[0]=velocidad;
    d["velocidad"].GetArray()[1]=velocidadBack;
    d["generacion"].GetArray()[0]=generacion;
    d["generacion"].GetArray()[1]=generacionBack;
    d["id"].GetArray()[0]=id;
    d["id"].GetArray()[1]=idBack;
    d["vida"].GetArray()[0]=vida;
    d["vida"].GetArray()[1]=vidaBack;
    d["fitness"].GetArray()[0]=fitness;
    d["fitness"].GetArray()[1]=fitnessBack;
    d["probabilidad"].GetArray()[0]=probabilidad;
    d["probabilidad"].GetArray()[1]=probabilidadBack;
    d["troncoSuperior"].GetArray()[0]=troncoSuperior;
    d["troncoSuperior"].GetArray()[1]=troncoSuperiorBack;
    d["troncoInferior"].GetArray()[0]=troncoInferior;
    d["troncoInferior"].GetArray()[1]=troncoInferiorBack;
    d["supervivenciaGen"].GetArray()[0]=supervivenciaGen;
    d["supervivenciaGen"].GetArray()[1]=supervivenciaGenBack;
    for (int j=0;j<10;j++){
        for(int i=0; i<10;i++){
        d["matrix"].GetArray()[j][i]=matrix[j][i];
        }

    }
    for (int j=0;j<30;j++){
        if(aStar[j][0]==9 and aStar[j][1]==9){
            d["aStar"].GetArray()[j][0]=aStar[j][0];
            d["aStar"].GetArray()[j][1]=aStar[j][1];
            break;
        }
        else{
            d["aStar"].GetArray()[j][0]=aStar[j][0];
            d["aStar"].GetArray()[j][1]=aStar[j][1];
        }

    }
    for (int j=0;j<30;j++){
        if(backTrack[j][0]==9 and backTrack[j][1]==9){
            d["backTrack"].GetArray()[j][0]=backTrack[j][0];
            d["backTrack"].GetArray()[j][1]=backTrack[j][1];
            break;
        }
        else{
            d["backTrack"].GetArray()[j][0]=backTrack[j][0];
            d["backTrack"].GetArray()[j][1]=backTrack[j][1];
        }

    }
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    d.Accept(writer);
    qDebug()<<buffer.GetString();
    return buffer.GetString();

}
string serializador::serializarGrafico(string grafico1, string grafico2){
    const char* json = "{\"grafico\":\"123456789\","
                       "\"grafico2\":\"123456789\"}";
    Document d;
    d.Parse(json);
    d["grafico"].SetString(grafico1.c_str(),sizeof(char)*grafico1.length());

    d["grafico2"].SetString(grafico2.c_str(),sizeof(char)*grafico2.length());
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


