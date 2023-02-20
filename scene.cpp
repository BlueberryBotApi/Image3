#include "scene.h"

Scene::Scene(QGraphicsScene *parent)
    :QGraphicsScene(parent)
{
    _imageEditor = new ImageEditor();
    addItem(background = new QGraphicsRectItem(0,0,1920,1080));
    background->setAcceptDrops(true);
    setSceneRect(0,0,1920,1080);
    upperImg = QImage(width(),height(),QImage::Format_ARGB32);
    upperImg.fill(Qt::transparent);
    item = addPixmap(QPixmap::fromImage(upperImg));
}
Scene::~Scene()
{
    delete item;
}
void Scene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
  const QMimeData* mimeData = event->mimeData();
  // check for our needed mime type, here a file or a list of files
  if (mimeData->hasUrls())
  {
    QList<QUrl> urlList = mimeData->urls();
    // extract the local paths of the files
    pathList=urlList.at(0).toLocalFile();
    loadAndSetImageToScene(pathList);
  }

}
void Scene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    event->acceptProposedAction();
}

void Scene::loadAndSetImageToScene(QString &str)
{
    for(int i = 0; i<items().count();i++)
    {
        if(items().at(i)!=this->background)
        {
            delete (items().at(i));
        }
    }
    update();
    img.load(str);
    img = img.scaled(this->width(),this->height(),Qt::KeepAspectRatio);
    img.convertTo(QImage::Format_ARGB32);
    openImageItem=addPixmap(QPixmap::fromImage(img));
    upperImg = QImage( img.width() , img.height() , QImage::Format_ARGB32);
    upperImg.fill( Qt::transparent );
    item = addPixmap( QPixmap::fromImage(upperImg ));
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    delete item;
    _imageEditor->changePixelColor(event->scenePos().x(),event->scenePos().y(), &upperImg);
    item=addPixmap(QPixmap::fromImage( upperImg ));
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    delete item;
    _imageEditor->changePixelColor(event->scenePos().x() , event->scenePos().y() , &upperImg);
    item=addPixmap(QPixmap::fromImage( upperImg ));
}
void Scene::save(QString &str)
{
    if(!img.isNull())
    {
        converToPNG();
        delete openImageItem;
        openImageItem=addPixmap(QPixmap::fromImage(img));
        upperImg.fill(Qt::transparent);
        img.save(str);
    }
}
void Scene::setPenSize(int value)
{
    _imageEditor->changePenSize(value);
}

void Scene::changeTooltoPen()
{
    _imageEditor->changeTooltoPen();
}
void Scene::changeTooltoEraser()
{
    _imageEditor->changeTooltoEraser();
}

void Scene::converToPNG()
{
    _imageEditor->convertToPng(&img, &upperImg);
}
