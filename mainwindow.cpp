#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QList>
#include "mymenu.h"
#include "mytoolbar.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a = new Scene();
    view = new QGraphicsView(a);
    view->fitInView(a->sceneRect(),Qt::KeepAspectRatio);
    view->setStyleSheet("background:transparent");
    view->setAcceptDrops(true);
    setCentralWidget(view);
    ui->centralwidget->setStyleSheet("background:transparent");
    setMinimumSize(400,300);
    setAcceptDrops(true);


    connect(this,&MainWindow::urlToScene,a,&Scene::loadAndSetImageToScene);
    connect(this,&MainWindow::saveImage,a,&Scene::save);
    ////////////////////////////////////////////////////////////////////////////////////////add and customize QMenuBar
    MyMenu *h=new MyMenu();
    setMenuBar(h);
            connect(h->close, &QAction::triggered, qApp, QApplication::quit);
            connect(h->open, &QAction::triggered, this, &MainWindow::GetURLofOpeningFile);
            connect(h->pen, &QAction::triggered, a, &Scene::changeTooltoPen);
            connect(h->eraser, &QAction::triggered, a, &Scene::changeTooltoEraser);

    /////////////////////////////////////////////////////////////////////////////////////// add and customize QToolBar
    MyToolBar *myToolBar=new MyToolBar();
    addToolBar(myToolBar);
            connect(myToolBar->save2, &QAction::triggered, this, &MainWindow::saveFile);
            connect(myToolBar->open2, &QAction::triggered, this, &MainWindow::GetURLofOpeningFile);
            connect(myToolBar->quit2, &QAction::triggered, qApp, &QApplication::quit);
            connect(myToolBar->penTool, &QAction::triggered, a, &Scene::changeTooltoPen);
            connect(myToolBar->eraserTool, &QAction::triggered, a, &Scene::changeTooltoEraser);
            connect(myToolBar->b, &QSlider::valueChanged, a, &Scene::changePenSize);
    a->sizeOfPen=myToolBar->b->value();

}

MainWindow::~MainWindow()
{

    //delete a;
    delete ui;
}

void MainWindow::GetURLofOpeningFile()
{
    QString str;
    str=QFileDialog::getOpenFileName(this,"Выберите изображение","C:/Users/Public/Pictures");
    emit urlToScene(str);

}

void MainWindow::saveFile()
{

    QString str;
    str=QFileDialog::getSaveFileName(this,"Выберете путь","",tr("*.png"));
    //QFileDialog::getOpenFileName(this,"Выберите изображение","C:/Users/Public/Pictures");
   // ui->statusbar->showMessage(str);
    emit saveImage(str);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    view->fitInView(a->sceneRect(),Qt::KeepAspectRatio);
}

