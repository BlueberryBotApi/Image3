#ifndef MYTOOLBAR_H
#define MYTOOLBAR_H
#include <QToolBar>
#include <QSlider>
class MyToolBar: public QToolBar
{
public:
    MyToolBar(QToolBar *parent = nullptr);
    QAction *save2, *open2, *penTool, *eraserTool,*quit2,*slider;
    QSlider *b;
    QAction *forSlider;
    ~MyToolBar();

};

#endif // MYTOOLBAR_H
