#include "cuerpograf.h"

cuerpograf::cuerpograf(float px_, float py_, float vx_, float vy_, float rad_, float escala_, float masa, float vin)
{
    esfera =  new cuerpo(px_, py_, vx_, vy_, rad_, masa, vin);
    escala = escala_;
}


QRectF cuerpograf::boundingRect() const
{
        return QRectF(-1*escala*esfera->getRad(),-1*escala*esfera->getRad(),2*escala*esfera->getRad(),2*escala*esfera->getRad());
}

void cuerpograf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkBlue);        //asigna el color
    painter->drawEllipse(boundingRect());    //dibuja una elipse encerrada en la boundingRect
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void cuerpograf::pos(int v_lim)
{
    setPos(esfera->getPx(),v_lim-(esfera->getPy()));
}

cuerpo *cuerpograf::getEsfera() const
{
    return esfera;
}

void cuerpograf::setEsfera(cuerpo *value)
{
    esfera = value;
}

float cuerpograf::getEscala() const
{
    return escala;
}

void cuerpograf::setEscala(float value)
{
    escala = value;
}

void cuerpograf::actualizar(float dt, int v_lim)
{
    //esfera->mover(dt);
    //pos(v_lim);

}

