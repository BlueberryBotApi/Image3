#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H
#include <QGraphicsItem>

class ImageEditor:public QObject
{
    Q_OBJECT
private:
    int _sizeOfPen, _typeOfToolColor=100;

public:
    ImageEditor();
public slots:
    void setPenSize(int value);
    void convertToPng(QImage *image,QImage *imagePattern);
    void changePixelColor(int x, int y,QImage *image);
    void changeTooltoPen();
    void changeTooltoEraser();

};

#endif // IMAGEEDITOR_H
