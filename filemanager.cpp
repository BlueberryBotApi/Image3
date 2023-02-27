#include "filemanager.h"

FileManager::FileManager()
{

}
QImage &FileManager::loadImage(QString &str)
{
    _openingImage22.load(str);
    _openingImage22.convertTo(QImage::Format_ARGB32);
    return _openingImage22;
}
void FileManager::saveImage(QString &str,QImage &img)
{
    img.save(str);
}
