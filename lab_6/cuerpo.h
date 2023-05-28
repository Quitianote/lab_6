#ifndef CUERPO_H
#define CUERPO_H
#define G 1
#define DT 1

#include <cmath>

class cuerpo
{
public:
    cuerpo(double px_=0, double py_=0, double vx_=0, double vy_=0, double rad_=10, double masa_ = 100);

    double getPx();
    void setPx();

    double getPy();
    void setPy();

    double getVx();
    void setVx(double m2);

    double getVy();
    void setVy(double m2);

    double getRad() const;

    void mover(double dt);

    void velocidad_y();
    void velocidad_x();

    void acel_x(double m2);
    void acel_y(double m2);

    double getAcelx();
    double getAcely();

    void setAng(double _ang);
    double getAng();

    void setDist(double _r);
    double getDist();

    void setMasa(double _masa);//creo que sobra
    double getMasa();//esto tambien

    double getPosinix();
    double getPosiniy();
    double getVinix();
    double getViniy();

private:
    double px;
    double py;
    const double rad;
    const double posx_ini;
    const double posy_ini;
    const double vin_x;
    const double vin_y;
    double vx;
    double vy;
    double ax;
    double ay;
    double ang;
    double r;
    double masa;

};


#endif // CUERPO_H
