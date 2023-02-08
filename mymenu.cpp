#include "mymenu.h"

MyMenu::MyMenu(QMenuBar *parent)
    :QMenuBar(parent)
{
//////////////////////////////////////////////////////////Files
    open = new QAction("&Open",this);
    close = new QAction("&Quit",this);
    save = new QAction("&SaveAs",this);

    QMenu *fileMenu =addMenu("&File");
    fileMenu->addAction(open);
    fileMenu->addAction(save);
    fileMenu->addSeparator();
    fileMenu->addAction(close);
//////////////////////////////////////////////////////////Tools
    pen = new QAction("&Pen",this);
    eraser = new QAction("&Eraser",this);

    QMenu *toolsMenu =addMenu("&Tools");
    toolsMenu->addAction(pen);
    toolsMenu->addAction(eraser);
}
