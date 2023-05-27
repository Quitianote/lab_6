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

void cuerpo::setVx()
{
    acel_x();
    vx = vin_x + (ax*DT);
    setPx;
}

float cuerpo::getVy()
{
    return vy;
}

void cuerpo::setVy()
{
    acel_y();
    vy = vin_y + (ay*DT);
    setPy;
}

float cuerpo::getAx() const
{
    return ax;
}

void cuerpo::setAx(float value)
{
    ax = value;
}

float cuerpo::getAy() const
{
    return ay;
}

void cuerpo::setAy(float value)
{
    ay = value;
}

float cuerpo::getRad() const
{
    return rad;
}

void cuerpo::mover(float dt)
{
    vy = vy - G*dt;
    if (int(vy) <= 0 && int(py) <= rad){ py=rad; vy=0;}
    px += vx*dt;
    py += vy*dt;
}

void cuerpo::acel_x()
{
    ax = ((G*masa)/(r*r))*cos(ang);
}

void cuerpo::acel_y()
{
    ay = ((G*masa)/(r*r))*sin(ang);
}

void cuerpo::setAng(float _ang)
{
    ang = _ang;
}

void cuerpo::setDist(float _r)
{
    r = _r;
}

void cuerpo::setMasa(float _masa)
{
    masa = _masa;
}

float cuerpo::getMasa()
{
    return masa;
}



