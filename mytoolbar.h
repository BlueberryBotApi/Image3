#ifndef MYTOOLBAR_H
#define MYTOOLBAR_H
#include <QToolBar>
#include <QSlider>
class MyToolBar: public QToolBar
{   
public: 
    MyToolBar(QMainWindow *parent = nullptr);
   const QAction *getSaveAction() ;
    ~MyToolBar();

    QAction *save2,*open2, *penTool, *eraserTool,*quit2,*slider;
    QSlider *sliderForChangingPenSize;
    QAction *forSlider;

};

#endif // MYTOOLBAR_H
