#include "mytoolbar.h"

MyToolBar::MyToolBar(QMainWindow *parent)
    :QToolBar()
{
    QPixmap forSave ( ":/icons/save.png" );
    QPixmap forOpen ( ":/icons/open.png" );
    QPixmap forClose ( ":/icons/close.png" );

    _saveImageAction=addAction ( QIcon( forSave ) , "Save File" );
    _openImageAction=addAction ( QIcon( forOpen ) , "New File" );
    addSeparator();

    QPixmap pen( ":/icons/pen.png" );
    QPixmap eraser( ":/icons/eraser.png" );

    _choicePenTool=addAction( QIcon ( pen ) , "Pen" );
    _choiceEraserTool=addAction( QIcon ( eraser ) , "Eraser" );
    addSeparator();
    _quitApp = addAction( QIcon ( forClose ) , "Quit Application" );
    _sliderForChangingPenSize=new QSlider( Qt::Horizontal );
    _sliderForChangingPenSize->setMinimum(1);
    _sliderForChangingPenSize->setMaximum(200);
    _sliderForChangingPenSize->setMaximumWidth(200);
    _sliderForChangingPenSize->setValue(20);
    addWidget( _sliderForChangingPenSize );

}

QSlider *MyToolBar::getSliderValue() const
{
    return _sliderForChangingPenSize;
}

QAction *MyToolBar::getSaveImageActionFromToolbar() const
{
    return _saveImageAction;
}

QAction *MyToolBar::getQuitApp() const
{
    return _quitApp;
}

QAction *MyToolBar::getEraserTool() const
{
    return _choiceEraserTool;
}

QAction *MyToolBar::getPenTool() const
{
    return _choicePenTool;
}
QAction *MyToolBar::getOpenImageFromToolbar() const
{
    return _openImageAction;
}
