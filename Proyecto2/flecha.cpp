#include "flecha.h"

flecha::flecha(int tipoTorre)
{
    int tipo = tipoTorre;
    switch (tipo) {

    case 1://flecha normal
        dano = 1;
        rango = 1;
        break;
    case 2://flecha fuego
        dano = 2;
        rango = 2;
        break;
    case 3://flecha explosiva
        dano = 4;
        rango = 2;
        break;
    }

}

void flecha::mover(int xObjetivo, int yObjetivo){//..........Agregar condicion del rango y la accion al llegar
    while(x!= xObjetivo && y != yObjetivo){
        if(xObjetivo > x){//derecha
            x += 5;
        }
        if(xObjetivo < x){//izquierda
            x -= 5;
        }
        if(yObjetivo < y){//arriba
            y -= 5;
        }
        if(yObjetivo > y){//abajo
            y += 5;
        }

    }
}

