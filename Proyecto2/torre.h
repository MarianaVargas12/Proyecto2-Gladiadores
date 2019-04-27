#ifndef TORRE_H
#define TORRE_H


class torre
{
private:
    int x,y;
public:
    int tipo;

    torre();
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
};

#endif // TORRE_H
