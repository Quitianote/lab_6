#ifndef ECUACIONES_H
#define ECUACIONES_H
#define G 1
#define DT 1

#include <cmath>
#include "cuerpo.h"

class ecuaciones
{
public:
    ecuaciones(float m1,float m2);

    float getFg();

    void setFg(float m1,float m2, float r);
    void cal(float m1,float m2, float r);

    float getAng();
    void setAng(float px1, float py1, float px2, float py2);

    float getDis();
    void setDis(float px1, float py1, float px2, float py2);

private:
    float Fg;
    float m1;
    float m2;
    float r;
    float ang;

};

#endif // ECUACIONES_H
