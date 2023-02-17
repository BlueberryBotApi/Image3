#include "mytoolbar.h"

MyToolBar::MyToolBar(QMainWindow *parent)
    :QToolBar()
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

    sliderForChangingPenSize=new QSlider(Qt::Horizontal);
    sliderForChangingPenSize->setMinimum(1);
    sliderForChangingPenSize->setMaximum(200);
    sliderForChangingPenSize->setMaximumWidth(200);
    sliderForChangingPenSize->setValue(20);
    addWidget(sliderForChangingPenSize);

}

const QAction *MyToolBar::getSaveAction()
{
    return save2;
}
MyToolBar::~MyToolBar()
{

}
//const QAction * MyToolBar::getSaveAction()
//{
//    return save2;
//}

//const QAction* MyToolBar::getOpenAction()
//{
//    return open2;
//}
