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
    myScene = new Scene();
    view = new QGraphicsView(myScene);
    setCentralWidget(view);
    setMinimumSize(400,300);
    setAcceptDrops(true);
    connect(this,&MainWindow::urlToScene,myScene,&Scene::loadAndSetImageToScene);
    connect(this,&MainWindow::saveImage,myScene,&Scene::save);
    ////////////////////////////////////////////////////////////////////////////////////////add and customize QMenuBar
    MyMenu *h=new MyMenu(this);
    setMenuBar(h);
            connect(h->close, &QAction::triggered, qApp, QApplication::quit);
            connect(h->open, &QAction::triggered, this, &MainWindow::GetURLofOpeningFile);
            connect(h->pen, &QAction::triggered, myScene, &Scene::changeTooltoPen);
            connect(h->eraser, &QAction::triggered, myScene, &Scene::changeTooltoEraser);
    /////////////////////////////////////////////////////////////////////////////////////// add and customize QToolBar
    MyToolBar *ToolBar=new MyToolBar(this);
    addToolBar(ToolBar);
            connect(ToolBar->getSaveAction(), &QAction::triggered, this, &MainWindow::saveFile);
            connect(ToolBar->open2, &QAction::triggered, this, &MainWindow::GetURLofOpeningFile);
            connect(ToolBar->quit2, &QAction::triggered, qApp, &QApplication::quit);
            connect(ToolBar->penTool, &QAction::triggered, myScene, &Scene::changeTooltoPen);
            connect(ToolBar->eraserTool, &QAction::triggered, myScene, &Scene::changeTooltoEraser);
            connect(ToolBar->sliderForChangingPenSize, &QSlider::valueChanged, myScene, &Scene::changePenSize);
    myScene->sizeOfPen=ToolBar->sliderForChangingPenSize->value();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GetURLofOpeningFile()
{
    QString str;
    str=QFileDialog::getOpenFileName(this , "Выберите изображение" , "C:/Users/Public/Pictures");
    emit urlToScene(str);
}

void MainWindow::saveFile()
{
    QString str;
    str=QFileDialog::getSaveFileName(this, "Выберете путь" , "", tr("*.png"));
    emit saveImage(str);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    view->fitInView(myScene->sceneRect(),Qt::KeepAspectRatio);
}

