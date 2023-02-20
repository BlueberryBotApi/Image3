#ifndef MYTOOLBAR_H
#define MYTOOLBAR_H
#include <QToolBar>
#include <QSlider>
class MyToolBar: public QToolBar
{   
public:
    MyToolBar(QMainWindow *parent = nullptr);
    QAction *getOpenImageFromToolbar() const;
    QAction *getPenTool() const;
    QAction *getEraserTool() const;
    QAction *getQuitApp() const;
    QSlider *getSliderValue() const;
    QSlider *_sliderForChangingPenSize;
    QAction *getSaveImageActionFromToolbar() const;
private:
    QAction *_saveImageAction, *_openImageAction, *_choicePenTool, *_choiceEraserTool, *_quitApp;



};

#endif // MYTOOLBAR_H
