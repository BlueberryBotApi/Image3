#ifndef MYMENU_H
#define MYMENU_H

#include <QMenuBar>
class MyMenu : public QMenuBar
{

public:
    MyMenu(QMenuBar *parent = nullptr);
    QAction *open,*close,*save,*pen,*eraser;

};

#endif // MYMENU_H
