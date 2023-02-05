#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H
#include <QGraphicsItem>

class ImageEditor
{
private:
    int sizeOfPen;
public:
    ImageEditor();
public slots:
    void changePenSize(int value);
    void convertToPng();
    void paint();

};

#endif // IMAGEEDITOR_H
