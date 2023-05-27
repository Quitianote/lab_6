#include "cuerpo.h"

cuerpo::cuerpo(float px_, float py_, float vx_, float vy_, float rad_, float masa_, float vin_):
    px(px_), py(py_),vx(vx_),vy(vy_),rad(rad_), masa(masa_), vin(vin_)
{

}

float cuerpo::getPx() const
{
    return px;
}

void cuerpo::setPx(float value)
{
    px = value;
}

float cuerpo::getPy() const
{
    return py;
}

void cuerpo::setPy(float value)
{
    py = value;
}

float cuerpo::getVx() const
{
    return vx;
}

void cuerpo::setVx(float value)
{
    vx = value;
}

float cuerpo::getVy() const
{
    return vy;
}

void cuerpo::setVy(float value)
{
    vy = value;
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
    //if(py<=0) vy = -vy;
    vy = vy - G*dt;
    if (int(vy) <= 0 && int(py) <= rad){ py=rad; vy=0;}
    px += vx*dt;
    py += vy*dt;
}

void cuerpo::velocidad_y(float vin, float ay){
    vy = vin + (ay*DT);
}

void cuerpo::velocidad_x(float vin, float ax){
    vx = vin + (ax*DT);
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



