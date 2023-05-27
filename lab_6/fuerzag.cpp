#include "fuerzag.h"

fuerzag::fuerzag(float _m1,float _m2, float _r)
{
    m1 = _m1;
    m2 = _m2;
    r = _r;
    setFg( m1, m2, r);
}

float fuerzag::getFg()
{
    return Fg;
}

void fuerzag::setFg(float m1,float m2, float r)
{
    Fg = ((G*m1*m2)/(r*r));
}

float fuerzag::getAng()
{
    return ang;
}

void fuerzag::setAng(float px1, float py1, float px2, float py2)
{
    ang = atan(((py2 - py1)/(px2 - px1)));
}

float fuerzag::getDis()
{
    return r;
}

void fuerzag::setDis(float px1, float py1, float px2, float py2)
{
    r = sqrt(pow((px2 - px1), 2) + pow((py2 - py1), 2));
}


