#include "ecuaciones.h"

ecuaciones::ecuaciones(float _m1,float _m2)
{
    m1 = _m1;
    m2 = _m2;
}

float ecuaciones::getFg()
{
    return Fg;
}

void ecuaciones::setFg(float m1,float m2, float r)
{
    Fg = ((G*m1*m2)/(r*r));
}

float ecuaciones::getAng()
{
    return ang;
}

void ecuaciones::setAng(float px1, float py1, float px2, float py2)
{
    ang = atan(((py2 - py1)/(px2 - px1)));
}

float ecuaciones::getDis()
{
    return r;
}

void ecuaciones::setDis(float px1, float py1, float px2, float py2)
{
    r = sqrt(pow((px2 - px1), 2) + pow((py2 - py1), 2));
}


