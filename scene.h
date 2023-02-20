#ifndef SCENERED_H
#define SCENERED_H
#include "imageeditor.h"

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
public slots:
    void loadAndSetImageToScene(QString &str);
    void save(QString &str);
    void setPenSize(int value);
    void changeTooltoPen();
    void changeTooltoEraser();
    void converToPNG();

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
