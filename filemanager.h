#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QImage>

class FileManager:public QObject
{
    Q_OBJECT
public:
    FileManager();
private:
    QImage _openingImage22;
public slots:
    QImage &loadImage(QString &str);
    void saveImage(QString &str,QImage &img);

};

#endif // FILEMANAGER_H
