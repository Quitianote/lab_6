#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "cuerpograf.h"
#include "ecuaciones.h"
#include "cuerpo.h"
#include <QTimer>

#define DT 0.1
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int v_limit;
    int h_limit;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void bordercollision(cuerpograf *b);

private slots:
    void actualizar();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    cuerpograf *obj1;
    cuerpograf *obj;
    ecuaciones *obj1_obj;
    QTimer *timer;

};
#endif // MAINWINDOW_H
