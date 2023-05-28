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

    obj = new cuerpograf(500,300,0,0,20,1, 10000);
    obj->pos();
    scene->addItem(obj);

    obj1 = new cuerpograf(400,500,50,100,10,1, 10);
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


    double posx = obj1->getplaneta()->getPx();
    double posy = obj1->getplaneta()->getPy();
    double velx = obj1->getplaneta()->getVx();
    double vely = obj1->getplaneta()->getVy();
    double acelx = obj1->getplaneta()->getAcelx();
    double acely = obj1->getplaneta()->getAcely();
    double radio = obj1->getplaneta()->getDist();
    double angulo = obj1->getplaneta()->getAng();
    double posx_ini = obj1->getplaneta()->getPosinix();
    double posy_ini = obj1->getplaneta()->getPosiniy();
    double velx_ini = obj1->getplaneta()->getVinix();
    double vely_ini = obj1->getplaneta()->getViniy();

    double posx2 = obj->getplaneta()->getPx();
    double posy2 = obj->getplaneta()->getPy();
    double velx2 = obj->getplaneta()->getVx();
    double vely2 = obj->getplaneta()->getVy();
    double acelx2 = obj->getplaneta()->getAcelx();
    double acely2 = obj->getplaneta()->getAcely();
    double radio2 = obj->getplaneta()->getDist();
    double angulo2 = obj->getplaneta()->getAng();
    double posx2_ini = obj->getplaneta()->getPosinix();
    double posy2_ini = obj->getplaneta()->getPosiniy();
    double velx2_ini = obj->getplaneta()->getVinix();
    double vely2_ini = obj->getplaneta()->getViniy();

    obj1->actualizar();
    obj->actualizar();

}



