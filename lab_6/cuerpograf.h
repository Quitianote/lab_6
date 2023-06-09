#ifndef CUERPOGRAF_H
#define CUERPOGRAF_H
#define DT 1
#include <QGraphicsItem>
#include <QPainter>
#include "cuerpo.h"

class cuerpograf: public QGraphicsItem

{
public:
    cuerpograf(double px_=0, double py_=0, double vx_=0, double vy_=0, double rad_=10, double escala_ = 1, double masa = 100);

    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto
    void pos();

    cuerpo *getplaneta() const;
    void setplaneta(cuerpo *value);

    float getEscala() const;
    void setEscala(float value);

    void actualizar();

    void cambiarColor(const QColor &newColor);

private:
    cuerpo *planeta;
    float escala;
    QColor color;

};


#endif // CUERPOGRAF_H
