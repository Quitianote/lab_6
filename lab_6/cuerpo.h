#ifndef CUERPO_H
#define CUERPO_H
#define G 6.67384
#define DT 0.1

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
    void setVx();

    float getVy();
    void setVy();

    float getAx() const;
    void setAx(float value);

    float getAy() const;
    void setAy(float value);

    float getRad() const;

    void mover(float dt);

    void velocidad_y();
    void velocidad_x();

    void acel_x();
    void acel_y();

    void setAng(float _ang);

    void setDist(float _r);

    void setMasa(float _masa);//creo que sobra
    float getMasa();//esto tambien


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
