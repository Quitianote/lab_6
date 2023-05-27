#ifndef FUERZAG_H
#define FUERZAG_H
#define G 6.67384
#define DT 0.1

#include <cmath>

class fuerzag
{
public:
    fuerzag(float m1,float m2, float r);

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

#endif // FUERZAG_H
