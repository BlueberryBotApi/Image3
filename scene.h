#ifndef SCENERED_H
#define SCENERED_H
#include "imageeditor.h"
#include "filemanager.h"

#include <QGraphicsScene>

#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

#include <QGraphicsSceneDragDropEvent>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QGraphicsScene *parent = nullptr);
    ~Scene();
    QImage _currentImage;
    QString _pathList;
    ImageEditor *_imageEditor;
    FileManager *_fileManager;
public slots:
    void loadAndSetImageToScene(QString &str);
    void save(QString &str);
    void converToPNG();
signals:
    void convertToPNG(QImage *_currentImage,QImage *_upperImg);
    void saveImageSignal(QString &str,QImage &img);
private:
    QImage _upperImg;
    QGraphicsRectItem *_background;
    QGraphicsPixmapItem *_upperImageItem, *_openImageItem;
    void convertToPng();
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void dropEvent( QGraphicsSceneDragDropEvent *event ) override;
    void dragEnterEvent( QGraphicsSceneDragDropEvent *event )override;
};

#endif // SCENERED_H
