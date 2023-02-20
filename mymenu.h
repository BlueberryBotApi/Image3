#ifndef MYMENU_H
#define MYMENU_H
#include <QMainWindow>
#include <QMenuBar>
class MyMenu : public QMenuBar
{

public:
    MyMenu(QMainWindow *parent = nullptr);
    QAction *getOpenImageFromMenuBar() const;
    QAction *getQuitApp() const;
    QAction *getSaveImageFromMenuBar() const;
    QAction *getPen() const;
    QAction *getEraser() const;
private:
    QAction *OpenImageAction,*quitApp,*saveImageAction,*pen,*eraser;
};

#endif // MYMENU_H
