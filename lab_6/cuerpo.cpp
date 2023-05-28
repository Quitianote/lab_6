#include "cuerpo.h"

cuerpo::cuerpo(float px_, float py_, float vx_, float vy_, float rad_, float masa_):
    px(px_), py(py_),vx(vx_),vy(vy_),rad(rad_), masa(masa_), vin_x(vx_), vin_y(vy_), posx_ini( px_), posy_ini( py_)
{

}

float cuerpo::getPx()
{
    return px;
}

void cuerpo::setPx()
{
    px = posx_ini + (vx*DT) + ((ax*pow(DT, 2)/2));
}

float cuerpo::getPy()
{
    return py;
}

void cuerpo::setPy()
{
    py = posy_ini + (vy*DT) + ((ay*pow(DT, 2)/2));
}

float cuerpo::getVx()
{
    return vx;
}

void cuerpo::setVx(float m2)
{
    acel_x(m2);
    vx = vin_x + (ax*DT);
    setPx();
}

float cuerpo::getVy()
{
    return vy;
}

void cuerpo::setVy(float m2)
{
    acel_y(m2);
    vy = vin_y + (ay*DT);
    setPy();
}

float cuerpo::getRad() const
{
    return rad;
}

void cuerpo::acel_x(float m2)
{
    ax = ((G*m2)/(r*r))*cos(ang);
}

void cuerpo::acel_y(float m2)
{
    ay = ((G*m2)/(r*r))*sin(ang);
}

float cuerpo::getAcelx()
{
    return ax;
}

float cuerpo::getAcely()
{
    return ay;
}

void cuerpo::setAng(float _ang)
{
    ang = _ang;
}

float cuerpo::getAng()
{
    return ang;
}

void cuerpo::setDist(float _r)
{
    r = _r;
}

float cuerpo::getDist()
{
    return r;
}

void cuerpo::setMasa(float _masa)
{
    masa = _masa;
}

float cuerpo::getMasa()
{
    return masa;
}

float cuerpo::getPosinix()
{
    return posx_ini;
}

float cuerpo::getPosiniy()
{
    return posy_ini;
}

float cuerpo::getVinix()
{
    return vin_x;
}

float cuerpo::getViniy()
{
    return vin_y;
}



