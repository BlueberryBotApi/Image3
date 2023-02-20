#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H
#include <QGraphicsItem>

class ImageEditor
{

private:
    int _sizeOfPen=20, _typeOfToolColor=100;

public:
    ImageEditor();
public slots:
    void changePenSize(int value);
    void convertToPng(QImage *image,QImage *imagePattern);
    void changePixelColor(int x, int y,QImage *image);
    void changeTooltoPen();
    void changeTooltoEraser();

};

#endif // IMAGEEDITOR_H
