#ifndef CUADRO_H
#define CUADRO_H


class cuadro
{
private:
    int x,y;

public:
    cuadro();
    bool ocupado = false;
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
};

#endif // CUADRO_H
