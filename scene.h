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
    QImage img;
    QString pathList;
    int sizeOfPen;
    ImageEditor *_imageEditor;
public slots:
    void loadAndSetImageToScene(QString &str);
    void save(QString &str);
    void setPenSize(int value);
    void changeTooltoPen();
    void changeTooltoEraser();
    void converToPNG();

private:
    int typeOfTool;
    QImage upperImg;
    QGraphicsRectItem* background;
    void convertToPng();
    QPointF previousPoint;
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void dropEvent( QGraphicsSceneDragDropEvent *event ) override;
    void dragEnterEvent( QGraphicsSceneDragDropEvent *event )override;
    QGraphicsPixmapItem* item;
    QGraphicsPixmapItem* openImageItem;
};

#endif // SCENERED_H
