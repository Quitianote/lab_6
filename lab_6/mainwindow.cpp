#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    h_limit = 1500;
    v_limit = 1000;
    scene->setSceneRect(0,0,h_limit,v_limit);
    scene->addRect(scene->sceneRect());
    ui->graphicsView->setScene(scene);

    obj = new cuerpograf(500,500,0,0,20,1, 10000);
    obj->pos();
    scene->addItem(obj);

    obj1 = new cuerpograf(50,100,5,0,10,1, 10);
    obj1->pos();
    scene->addItem(obj1);

    obj1->cambiarColor(Qt::red);

    obj1_obj = new ecuaciones(obj1->getplaneta()->getMasa(), obj->getplaneta()->getMasa());//inicializando fuerza de gravedad

    timer = new QTimer;
    timer->stop();
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar()));
    timer->start(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::actualizar()
{
    obj1_obj->setDis(obj1->getplaneta()->getPx(),obj1->getplaneta()->getPy(),obj->getplaneta()->getPx(),obj->getplaneta()->getPy());//creando distancia

    obj1_obj->setAng(obj1->getplaneta()->getPx(),obj1->getplaneta()->getPy(),obj->getplaneta()->getPx(),obj->getplaneta()->getPy());//creando angulo
    //ahora calcular la velocidad
    obj1->getplaneta()->setAng(obj1_obj->getAng());//actualizando angulo
    obj1->getplaneta()->setDist(obj1_obj->getDis());//actualizando distancia
    obj1->getplaneta()->setVx(obj->getplaneta()->getMasa());
    obj1->getplaneta()->setVy(obj->getplaneta()->getMasa());

    obj->getplaneta()->setAng(obj1_obj->getAng());//actualizando angulo
    obj->getplaneta()->setDist(obj1_obj->getDis());//actualizando distancia
    obj->getplaneta()->setVx(obj1->getplaneta()->getMasa());
    obj->getplaneta()->setVy(obj1->getplaneta()->getMasa());


    float posx = obj1->getplaneta()->getPx();
    float posy = obj1->getplaneta()->getPy();
    float velx = obj1->getplaneta()->getVx();
    float vely = obj1->getplaneta()->getVy();
    float acelx = obj1->getplaneta()->getAcelx();
    float acely = obj1->getplaneta()->getAcely();
    float radio = obj1->getplaneta()->getDist();
    float angulo = obj1->getplaneta()->getAng();
    float posx_ini = obj1->getplaneta()->getPosinix();
    float posy_ini = obj1->getplaneta()->getPosiniy();
    float velx_ini = obj1->getplaneta()->getVinix();
    float vely_ini = obj1->getplaneta()->getViniy();

    float posx2 = obj->getplaneta()->getPx();
    float posy2 = obj->getplaneta()->getPy();
    float velx2 = obj->getplaneta()->getVx();
    float vely2 = obj->getplaneta()->getVy();
    float acelx2 = obj->getplaneta()->getAcelx();
    float acely2 = obj->getplaneta()->getAcely();
    float radio2 = obj->getplaneta()->getDist();
    float angulo2 = obj->getplaneta()->getAng();
    float posx2_ini = obj->getplaneta()->getPosinix();
    float posy2_ini = obj->getplaneta()->getPosiniy();
    float velx2_ini = obj->getplaneta()->getVinix();
    float vely2_ini = obj->getplaneta()->getViniy();

    obj1->actualizar();
    obj->actualizar();

}



