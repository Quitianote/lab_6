#include "cuerpograf.h"

cuerpograf::cuerpograf(float px_, float py_, float vx_, float vy_, float rad_, float escala_, float masa)
{
    planeta =  new cuerpo(px_, py_, vx_, vy_, rad_, masa);
    escala = escala_;
}


QRectF cuerpograf::boundingRect() const
{
        return QRectF(-1*escala*planeta->getRad(),-1*escala*planeta->getRad(),2*escala*planeta->getRad(),2*escala*planeta->getRad());
}

void cuerpograf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(color);        //asigna el color
    painter->drawEllipse(boundingRect());    //dibuja una elipse encerrada en la boundingRect
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void cuerpograf::pos()
{
    setPos(planeta->getPx(),planeta->getPy());
}

cuerpo *cuerpograf::getplaneta() const
{
    return planeta;
}

void cuerpograf::setplaneta(cuerpo *value)
{
    planeta = value;
}

float cuerpograf::getEscala() const
{
    return escala;
}

void cuerpograf::setEscala(float value)
{
    escala = value;
}

void cuerpograf::actualizar()
{
    pos();

}
void cuerpograf::cambiarColor(const QColor &newColor)
{
    color = newColor;
}
