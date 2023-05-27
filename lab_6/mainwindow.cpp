#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    h_limit = 1000;
    v_limit = 1000;
    scene->setSceneRect(0,0,h_limit,v_limit);
    scene->addRect(scene->sceneRect());
    ui->graphicsView->setScene(scene);

    obj1 = new cuerpograf(500,500,2,0,20,1, 100);
    obj1->pos();
    scene->addItem(obj1);

    obj = new cuerpograf(50,900,200,2,20,1, 10);
    obj->pos();
    scene->addItem(obj);


    obj1_obj = new ecuaciones(obj1->getplaneta()->getMasa(), obj->getplaneta()->getMasa());//inicializando fuerza de gravedad

    obj1_obj->setDis(obj1->getplaneta()->getPx(),obj1->getplaneta()->getPy(),obj->getplaneta()->getPx(),obj->getplaneta()->getPy());//creando distancia

    obj1_obj->setAng(obj1->getplaneta()->getPx(),obj1->getplaneta()->getPy(),obj->getplaneta()->getPx(),obj->getplaneta()->getPy());

    //ahora calcular la velocidad
    obj1->getplaneta()->setAng(obj1_obj->getAng());//actualizando angulo
    obj1->getplaneta()->setDist(obj1_obj->getDis());//actualizando distancia
    obj1->getplaneta()->setVx();
    obj1->getplaneta()->setVy();


    timer = new QTimer;
    timer->stop();
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar()));
    timer->start(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::bordercollision(cuerpograf *b)
{
    if(b->getplaneta()->getPx() < b->getplaneta()->getRad() || b->getplaneta()->getPx() > h_limit-b->getplaneta()->getRad()){
        b->getplaneta()->setVx(b->getplaneta()->getVx()*-0.8);
    }

    if(b->getplaneta()->getPy() < b->getplaneta()->getRad() || b->getplaneta()->getPy() > v_limit-b->getplaneta()->getRad()){
        b->getplaneta()->setVy(b->getplaneta()->getVy()*-0.9);
    }

}*/

void MainWindow::actualizar()
{
    obj->actualizar(DT,v_limit);
    //bordercollision(obj);
}

