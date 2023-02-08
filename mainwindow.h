#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scene.h"

#include <QIcon>
#include <QMenuBar>
#include <QToolBar>
#include <QObject>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QWidget>

#include <QRectF>

#include <QVBoxLayout>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
  Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    //QMenu *fileMenu, *toolsMenu;
    //QAction *open,*close,*save,*pen, *eraser;
    QGraphicsView *view;
    Ui::MainWindow *ui;
    Scene *myScene;
    void GetURLofOpeningFile();
    void makeMenu();
    void makeToolBar();
    void saveFile();
    void resizeEvent(QResizeEvent* event);
signals:
    void urlToScene(QString &str);
    void saveImage(QString &str);

};
#endif // MAINWINDOW_H
