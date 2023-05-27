#ifndef CUERPO_H
#define CUERPO_H
#define G 6.67384
#define DT 0.1

#include <cmath>

class cuerpo
{
public:
    cuerpo(float px_=0, float py_=0, float vx_=0, float vy_=0, float rad_=10, float masa_ = 100, float vin_ = 0);

    float getPx() const;
    void setPx(float value);

    float getPy() const;
    void setPy(float value);

    float getVx() const;
    void setVx(float value);

    float getVy() const;
    void setVy(float value);

    float getAx() const;
    void setAx(float value);

    float getAy() const;
    void setAy(float value);

    float getRad() const;

    void mover(float dt);

    void velocidad_y(float vin, float ay);
    void velocidad_x(float vin, float ax);

    void acel_x();
    void acel_y();

    void distancia();

    void setAng(float _ang);

    void setDist(float _r);


private:
    float px;
    float py;
    const float rad;
    float vin;
    float vx;
    float vy;
    float ax;
    float ay;
    float ang;
    float r;
    float masa;

};


#endif // CUERPO_H
