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

    QGraphicsView *view;
    QImage img;

    QString pathList;
    int sizeOfPen;
protected:

    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event)override;
signals:

public slots:
    void loadAndSetImageToScene(QString &str);
    void save(QString &str);
    void changePenSize(int value);
    void changeTooltoPen();
    void changeTooltoEraser();
    void converToPNG();

private:
    int typeOfTool;
    QImage *upperImg;
    QGraphicsRectItem* background;
    void convertToPng();
    QPointF previousPoint;
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    QGraphicsPixmapItem* item;
    QGraphicsPixmapItem* openImageItem;
};

#endif // SCENERED_H
