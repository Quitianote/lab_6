#ifndef CUERPO_H
#define CUERPO_H
#define G 1
#define DT 1

#include <cmath>

class cuerpo
{
public:
    cuerpo(float px_=0, float py_=0, float vx_=0, float vy_=0, float rad_=10, float masa_ = 100);

    float getPx();
    void setPx();

    float getPy();
    void setPy();

    float getVx();
    void setVx(float m2);

    float getVy();
    void setVy(float m2);

    float getRad() const;

    void mover(float dt);

    void velocidad_y();
    void velocidad_x();

    void acel_x(float m2);
    void acel_y(float m2);

    float getAcelx();
    float getAcely();

    void setAng(float _ang);
    float getAng();

    void setDist(float _r);
    float getDist();

    void setMasa(float _masa);//creo que sobra
    float getMasa();//esto tambien

    float getPosinix();
    float getPosiniy();
    float getVinix();
    float getViniy();

private:
    float px;
    float py;
    const float rad;
    const float posx_ini;
    const float posy_ini;
    const float vin_x;
    const float vin_y;
    float vx;
    float vy;
    float ax;
    float ay;
    float ang;
    float r;
    float masa;

};


#endif // CUERPO_H
