#include "mymenu.h"

MyMenu::MyMenu(QMainWindow *parent)
    :QMenuBar(parent)
{
//////////////////////////////////////////////////////////Files
    open = new QAction("&Open", this);//load Image of Icons
    close = new QAction("&Quit", this);
    save = new QAction("&SaveAs", this);

    QMenu *fileMenu =addMenu("&File");//add  menu "File"
    fileMenu->addAction(open);//add actions to menu "File"
    fileMenu->addAction(save);
    fileMenu->addSeparator();
    fileMenu->addAction(close);
//////////////////////////////////////////////////////////Tools
    pen = new QAction("&Pen",this);//load Image of Icons
    eraser = new QAction("&Eraser",this);

    QMenu *toolsMenu =addMenu("&Tools");//add  menu "Tools"
    toolsMenu->addAction(pen);//add actions to menu "Tools"
    toolsMenu->addAction(eraser);
}
