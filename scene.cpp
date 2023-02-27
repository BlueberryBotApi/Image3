#include "scene.h"


Scene::Scene(QGraphicsScene *parent)
    :QGraphicsScene(parent)
{
    _imageEditor = new ImageEditor();
    _fileManager = new FileManager();

    addItem(_background = new QGraphicsRectItem(0,0,1920,1080));
    _background->setAcceptDrops(true);
    setSceneRect(0,0,1920,1080);
    _upperImg = QImage(width(),height(),QImage::Format_ARGB32);
    _upperImg.fill(Qt::transparent);
    _upperImageItem = addPixmap(QPixmap::fromImage(_upperImg));
    connect(this, &Scene::convertToPNG, _imageEditor, &ImageEditor::convertToPng);
    connect(this, &Scene::saveImageSignal, _fileManager, &FileManager::saveImage);
}
Scene::~Scene()
{
    delete _openImageItem;
    delete _upperImageItem;
}
void Scene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
  const QMimeData* mimeData = event->mimeData();
  // check for our needed mime type, here a file or a list of files
  if (mimeData->hasUrls())
  {
    QList<QUrl> urlList = mimeData->urls();
    // extract the local paths of the files
    _pathList=urlList.at(0).toLocalFile();
    loadAndSetImageToScene(_pathList);
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
        if(items().at(i)!=this->_background)
        {
            delete (items().at(i));
        }
    }
    update();
    _currentImage.load(str);
    _currentImage = _currentImage.scaled(this->width(),this->height(),Qt::KeepAspectRatio);
    _currentImage.convertTo(QImage::Format_ARGB32);
    _openImageItem=addPixmap(QPixmap::fromImage(_currentImage));
    _upperImg = QImage( _currentImage.width() , _currentImage.height() , QImage::Format_ARGB32);
    _upperImg.fill( Qt::transparent );
    _upperImageItem = addPixmap( QPixmap::fromImage(_upperImg ));
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    delete _upperImageItem;
    _imageEditor->changePixelColor(event->scenePos().x(),event->scenePos().y(), &_upperImg);
    _upperImageItem=addPixmap(QPixmap::fromImage( _upperImg ));
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    delete _upperImageItem;
    _imageEditor->changePixelColor(event->scenePos().x() , event->scenePos().y() , &_upperImg);
    _upperImageItem=addPixmap(QPixmap::fromImage( _upperImg ));
}
void Scene::save(QString &str)
{
    if(!_currentImage.isNull()&&!str.isNull())
    {
        converToPNG();
        delete _openImageItem;
        _openImageItem=addPixmap(QPixmap::fromImage(_currentImage));
        _upperImg.fill(Qt::transparent);
        emit saveImageSignal(str, *&_currentImage);
       // _currentImage.save(str);
    }
}

void Scene::converToPNG()
{
    emit convertToPNG(&_currentImage, &_upperImg);
}
