#include "torre.h"
#include <cstdlib>
#include <ctime>
int torre::getX() const
{
    return x;
}

void torre::setX(int value)
{
    x = value;
}

int torre::getY() const
{
    return y;
}

void torre::setY(int value)
{
    y = value;
}

torre::torre()
{
    //    srand(time(0));
    //    tipo = rand()%3+1;
    //    switch (tipo) {
//    case 1:
//        break;
//    }
}
