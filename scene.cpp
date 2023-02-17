#include "scene.h"

Scene::Scene(QGraphicsScene *parent)
    :QGraphicsScene(parent)
{
    addItem(background = new QGraphicsRectItem(0,0,1920,1080));
    background->setAcceptDrops(true);
    setSceneRect(0,0,1920,1080);
    upperImg = new QImage(width(),height(),QImage::Format_RGBA64);
    upperImg->fill(Qt::transparent);
    item = addPixmap(QPixmap::fromImage(*upperImg));
    typeOfTool=100;
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
    openImageItem=addPixmap(QPixmap::fromImage(img));
    delete upperImg;
    upperImg = new QImage( img.width() , img.height() , QImage::Format_RGBA64);
    upperImg->fill( Qt::transparent );
    item = addPixmap( QPixmap::fromImage( *upperImg ));
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

        delete item;


    for(int i=-sizeOfPen;i<sizeOfPen;i++)
    {
        if(event->scenePos().x()+i<upperImg->width()&&event->scenePos().x()+i>0)
        {
            for(int j=-sizeOfPen;j<sizeOfPen;j++)
            {
                if(event->scenePos().y()+j<upperImg->height()&&event->scenePos().y()+j>0)
                {
                upperImg->setPixelColor(event->scenePos().x()+i,event->scenePos().y()+j,QColor(0,255,0,typeOfTool));
                }
            }
        }
    }
    item=addPixmap(QPixmap::fromImage( *upperImg ));
    previousPoint = event->scenePos();
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    delete item;
    for(int i=-sizeOfPen;i<sizeOfPen;i++)
    {
        if(event->scenePos().x()+i<upperImg->width()&&event->scenePos().x()+i>0)
        {
            for(int j=-sizeOfPen;j<sizeOfPen;j++)
            {
                if(event->scenePos().y()+j < upperImg->height() && event->scenePos().y() + j >0 )
                {
                upperImg->setPixelColor( event->scenePos().x() + i , event->scenePos().y() + j, QColor(0,255,0,typeOfTool) );
                }
            }
        }
    }
    item=addPixmap(QPixmap::fromImage( *upperImg ));
    previousPoint = event->scenePos();
}
void Scene::save(QString &str)
{
    if(!img.isNull())
    {
        converToPNG();

        delete openImageItem;
        openImageItem=addPixmap(QPixmap::fromImage(img));
        upperImg->fill(Qt::transparent);
        //delete openImageItem;
        img.save(str);
    }
}
void Scene::changePenSize(int value)
{
    sizeOfPen=value;
}

void Scene::changeTooltoPen()
{
    typeOfTool=100;
}
void Scene::changeTooltoEraser()
{
    typeOfTool=0;
}

void Scene::converToPNG()
{
    img.convertTo(QImage::Format_ARGB32);
    for(int i=0;i<img.width();i++)
    {
        for(int j=0;j<img.height();j++)
        {
            if( upperImg->pixelColor( i , j )== Qt::transparent || upperImg->pixelColor(i,j) == QColor(0,255,0,0) )
            {
                img.setPixelColor( i , j , Qt::transparent );
            }
        }
    }
}
