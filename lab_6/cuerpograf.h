#ifndef CUERPOGRAF_H
#define CUERPOGRAF_H
#define DT 0.1
#include <QGraphicsItem>
#include <QPainter>
#include "cuerpo.h"

class cuerpograf: public QGraphicsItem

{
public:
    cuerpograf(float px_=0, float py_=0, float vx_=0, float vy_=0, float rad_=10, float escala_ = 1, float masa = 100, float vin = 0);

    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto
    void pos(int v_lim);

    cuerpo *getEsfera() const;
    void setEsfera(cuerpo *value);

    float getEscala() const;
    void setEscala(float value);

    void actualizar(float dt, int v_lim);

private:
    cuerpo *esfera;
    float escala;
};


#endif // CUERPOGRAF_H
