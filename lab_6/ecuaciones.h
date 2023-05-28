#ifndef ECUACIONES_H
#define ECUACIONES_H
#define G 1
#define DT 1

#include <cmath>
#include "cuerpo.h"

class ecuaciones
{
public:
    ecuaciones(double m1,double m2);

    double getFg();

    void setFg(double m1,double m2, double r);
    void cal(double m1,double m2, double r);

    double getAng();
    void setAng(double px1, double py1, double px2, double py2);

    double getDis();
    void setDis(double px1, double py1, double px2, double py2);

private:
    double Fg;
    double m1;
    double m2;
    double r;
    double ang;

};

#endif // ECUACIONES_H
