
#include <QImage>
#include <QImageReader>

#include "imageview.h"

#include "qhashfunctions.h"
#include "qimage.h"
#include "qpixmap.h"

imageview::imageview(QWidget* parent)
    : QGraphicsView(parent)
{
  scene = new QGraphicsScene(this);

  setScene(scene);

  auto* imagepath = new QString("/home/ubuntu/imageviewer/cat.jpg");
  QImageReader reader(*imagepath);
  QImage img = reader.read();

  item = new QGraphicsPixmapItem(QPixmap::fromImage(img));
  scene->addItem(item);
  scene->setSceneRect(item->boundingRect());
}
