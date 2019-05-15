#ifndef FLECHA_H
#define FLECHA_H



class flecha
{
public:
    int x,y,tipo,dano,rango,areaDano;
    //!
    //! \brief mover modifica el x,y de la flecha para desplazarla
    //! \param xObjetivo indica la distancia en x a la que se debe mover
    //! \param yObjetivo indica la distancia en y a la que se debe mover
    //!
    void mover(int xObjetivo,int yObjetivo);
    void accion();
    //!
    //! \brief flecha crea una flecha y segun el tipo le cambia el dano y el rango
    //! \param tipoTorre indica el tipo de flecha que debe ser creada segun la torre
    //!
    flecha(int tipoTorre);
};

#endif // FLECHA_H
