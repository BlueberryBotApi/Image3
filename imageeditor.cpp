#include "imageeditor.h"

ImageEditor::ImageEditor()
{

}
void ImageEditor::changePixelColor(int x, int y,QImage *image)
{
    for(int i=-_sizeOfPen;i<_sizeOfPen;i++)
    {
        if(x+i<image->width()&&x+i>0)
        {
            for(int j=-_sizeOfPen;j<_sizeOfPen;j++)
            {
                if(y+j<image->height()&&y+j>0)
                {
                    (*image).setPixelColor(x+i,y+j,QColor(0,255,0,_typeOfToolColor));
                }
            }
        }
    }
}
void ImageEditor::setPenSize(int value)
{
    _sizeOfPen = value;
}

void ImageEditor::changeTooltoPen()
{
    _typeOfToolColor=100;
}
void ImageEditor::changeTooltoEraser()
{
    _typeOfToolColor=0;
}
void ImageEditor::convertToPng(QImage *image,QImage *imagePattern)
{
    image->convertTo(QImage::Format_ARGB32);
    for(int i=0;i<image->width();i++)
    {
        for(int j=0;j<image->height();j++)
        {
            if( imagePattern->pixelColor( i , j )== Qt::transparent || imagePattern->pixelColor(i,j) == QColor(0,255,0,0) )
            {
                image->setPixelColor( i , j , Qt::transparent );
            }
        }
    }

}
