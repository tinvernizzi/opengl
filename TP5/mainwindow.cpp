#include "cubepolytech.h"
#include "cube.h"
#include "cubetex.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cubeeclaire.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::creeCube()
{
    CubeEclaire *m_cube = new CubeEclaire();
    m_cube->setPosition(ui->x->value(),ui->y->value(),ui->z->value());
    m_cube->setOrientation(ui->roulis->value(),ui->tangage->value(),ui->lacet->value());
    ui->openGLWidget->addDrawable(m_cube);
}
