#include "mymenu.h"

MyMenu::MyMenu(QMainWindow *parent)
    :QMenuBar(parent)
{
//////////////////////////////////////////////////////////Files
    OpenImageFromMenuBar = new QAction("&Open", this);//load Image of Icons
    quitApp = new QAction("&Quit", this);
    saveImageFromMenuBar = new QAction("&SaveAs", this);

    QMenu *fileMenu =addMenu("&File");//add  menu "File"
    fileMenu->addAction(OpenImageFromMenuBar);//add actions to menu "File"
    fileMenu->addAction(saveImageFromMenuBar);
    fileMenu->addSeparator();
    fileMenu->addAction(quitApp);
//////////////////////////////////////////////////////////Tools
    pen = new QAction("&Pen",this);//load Image of Icons
    eraser = new QAction("&Eraser",this);

    QMenu *toolsMenu =addMenu("&Tools");//add  menu "Tools"
    toolsMenu->addAction(pen);//add actions to menu "Tools"
    toolsMenu->addAction(eraser);
}

QAction *MyMenu::getEraser() const
{
    return eraser;
}

QAction *MyMenu::getPen() const
{
    return pen;
}

QAction *MyMenu::getSaveImageFromMenuBar() const
{
    return saveImageFromMenuBar;
}

QAction *MyMenu::getQuitApp() const
{
    return quitApp;
}

QAction *MyMenu::getOpenImageFromMenuBar() const
{
    return OpenImageFromMenuBar;
}
