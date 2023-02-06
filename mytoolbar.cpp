#include "mytoolbar.h"

MyToolBar::MyToolBar(QToolBar *parent)
    :QToolBar(parent)
{
    QPixmap forSave(":/icons/save.png");
    QPixmap forOpen(":/icons/open.png");
    QPixmap forClose(":/icons/close.png");

    save2=addAction(QIcon(forSave),"Save File");
     //connect(save2, &QAction::triggered, this, &MainWindow::saveFile);
    open2=addAction(QIcon(forOpen), "New File");
    //connect(open2, &QAction::triggered, this, &MainWindow::GetURLofOpeningFile);
    addSeparator();
//////////////////////////////////////////////////////////Tools
    QPixmap pen(":/icons/pen.png");
    QPixmap eraser(":/icons/eraser.png");
    penTool=addAction(QIcon(pen),"Pen");
     //connect(save2, &QAction::triggered, this, &MainWindow::saveFile);
    eraserTool=addAction(QIcon(eraser), "Eraser");
    //connect(open2, &QAction::triggered, this, &MainWindow::GetURLofOpeningFile);
    addSeparator();

    quit2 = addAction(QIcon(forClose),"Quit Application");

    b=new QSlider(Qt::Horizontal);
    b->setMinimum(1);
    b->setMaximum(200);
    b->setMaximumWidth(200);
    b->setValue(20);
    addWidget(b);

    //connect(quit2, &QAction::triggered, qApp, &QApplication::quit);
}
MyToolBar::~MyToolBar()
{
//   delete b;
//   delete forSlider;
}
