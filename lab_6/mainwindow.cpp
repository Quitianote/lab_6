#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,2000,1000);
    scene->addRect(scene->sceneRect());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

    obj = new cuerpograf(500,300,0,0,200,2, 10000);
    obj->pos();
    scene->addItem(obj);

    obj1 = new cuerpograf(4000,1000,50,-25,100,2, 10);
    obj1->pos();
    scene->addItem(obj1);

    obj1->cambiarColor(Qt::red);

    obj1_obj = new ecuaciones(obj1->getplaneta()->getMasa(), obj->getplaneta()->getMasa());//inicializando fuerza de gravedad

    timer = new QTimer;
    timer->stop();
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar()));
    timer->start(100);

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
    double radio_ant = obj1->getplaneta()->getAnt();
    obj1->getplaneta()->setVx(obj->getplaneta()->getMasa());
    obj1->getplaneta()->setVy(obj->getplaneta()->getMasa());



    obj->getplaneta()->setAng(obj1_obj->getAng());//actualizando angulo
    obj->getplaneta()->setDist(obj1_obj->getDis());//actualizando distancia
    double radio_ant2 = obj->getplaneta()->getAnt();
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



