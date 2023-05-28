#include "cuerpo.h"

cuerpo::cuerpo(double px_, double py_, double vx_, double vy_, double rad_, double masa_):
    px(px_), py(py_),vx(vx_),vy(vy_),rad(rad_), masa(masa_), vin_x(vx_), vin_y(vy_), posx_ini( px_), posy_ini( py_)
{

}

double cuerpo::getPx()
{
    return px;
}

void cuerpo::setPx()
{
    px = px- (posx_ini + vx + (ax/2));
    if(px < 0)px *= -1;
}

double cuerpo::getPy()
{
    return py;
}

void cuerpo::setPy()
{
    py = py - (posy_ini + vy + (ay/2));
    if(py < 0)py *= -1;
}

double cuerpo::getVx()
{
    return vx;
}

void cuerpo::setVx(double m2)
{
    acel_x(m2);
    vx = vin_x + (ax*DT);
    setPx();
}

double cuerpo::getVy()
{
    return vy;
}

void cuerpo::setVy(double m2)
{
    acel_y(m2);
    vy = vin_y + (ay*DT);
    setPy();
}

double cuerpo::getRad() const
{
    return rad;
}

void cuerpo::acel_x(double m2)
{
    ax = (m2/(r*r))*cos(ang);
}

void cuerpo::acel_y(double m2)
{
    ay = (m2/(r*r))*sin(ang);
}

double cuerpo::getAcelx()
{
    return ax;
}

double cuerpo::getAcely()
{
    return ay;
}

void cuerpo::setAng(double _ang)
{
    ang = _ang;
}

double cuerpo::getAng()
{
    return ang;
}

void cuerpo::setDist(double _r)
{
    r = _r;
}

double cuerpo::getDist()
{
    return r;
}

void cuerpo::setMasa(double _masa)
{
    masa = _masa;
}

double cuerpo::getMasa()
{
    return masa;
}

double cuerpo::getPosinix()
{
    return posx_ini;
}

double cuerpo::getPosiniy()
{
    return posy_ini;
}

double cuerpo::getVinix()
{
    return vin_x;
}

double cuerpo::getViniy()
{
    return vin_y;
}



