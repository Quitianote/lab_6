#include "ecuaciones.h"

ecuaciones::ecuaciones(double _m1,double _m2)
{
    m1 = _m1;
    m2 = _m2;
}

double ecuaciones::getFg()
{
    return Fg;
}

void ecuaciones::setFg(double m1,double m2, double r)
{
    Fg = ((G*m1*m2)/(r*r));
}

double ecuaciones::getAng()
{
    return ang;
}

void ecuaciones::setAng(double px1, double py1, double px2, double py2)
{
    ang = atan2(py2 - py1,px2 - px1);
}

double ecuaciones::getDis()
{
    return r;
}

void ecuaciones::setDis(double px1, double py1, double px2, double py2)
{
    r = sqrt(pow((px2 - px1), 2) + pow((py2 - py1), 2));
}


