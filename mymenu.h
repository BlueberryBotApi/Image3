#ifndef MYMENU_H
#define MYMENU_H
#include <QMainWindow>
#include <QMenuBar>
class MyMenu : public QMenuBar
{

public:
    MyMenu(QMainWindow *parent = nullptr);
    QAction *open,*close,*save,*pen,*eraser;

};

#endif // MYMENU_H
