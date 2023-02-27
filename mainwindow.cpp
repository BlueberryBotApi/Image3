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
    _myScene = new Scene();
    _view = new QGraphicsView(_myScene);
    setCentralWidget(_view);
    setMinimumSize(400,300);
    setAcceptDrops(true);
    connect(this,&MainWindow::urlToScene,_myScene,&Scene::loadAndSetImageToScene);
    connect(this,&MainWindow::saveImage,_myScene,&Scene::save);
    ////////////////////////////////////////////////////////////////////////////////////////add and customize QMenuBar
    MyMenu *h=new MyMenu(this);
    setMenuBar(h);
            connect(h->getQuitApp(), &QAction::triggered, qApp, QApplication::quit);
            connect(h->getOpenImageFromMenuBar(), &QAction::triggered, this, &MainWindow::GetURLofOpeningFile);
            connect(h->getPen(), &QAction::triggered, _myScene->_imageEditor, &ImageEditor::changeTooltoPen);
            connect(h->getEraser(), &QAction::triggered, _myScene->_imageEditor, &ImageEditor::changeTooltoEraser);
    /////////////////////////////////////////////////////////////////////////////////////// add and customize QToolBar
    MyToolBar *ToolBar=new MyToolBar(this);
    addToolBar(ToolBar);
            connect(ToolBar->getSaveImageActionFromToolbar(), &QAction::triggered, this, &MainWindow::saveFile);
            connect(ToolBar->getOpenImageFromToolbar(), &QAction::triggered, this, &MainWindow::GetURLofOpeningFile);
            connect(ToolBar->getQuitApp(), &QAction::triggered, qApp, &QApplication::quit);
            connect(ToolBar->getPenTool(), &QAction::triggered, _myScene->_imageEditor, &ImageEditor::changeTooltoPen);
            connect(ToolBar->getEraserTool(), &QAction::triggered, _myScene->_imageEditor, &ImageEditor::changeTooltoEraser);
            connect(ToolBar->_sliderForChangingPenSize, &QSlider::valueChanged, _myScene->_imageEditor, &ImageEditor::setPenSize);
    _myScene->_imageEditor->setPenSize(ToolBar->_sliderForChangingPenSize->value());

}

MainWindow::~MainWindow()
{
    //delete _myScene;
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
    _view->fitInView(_myScene->sceneRect(),Qt::KeepAspectRatio);
}

