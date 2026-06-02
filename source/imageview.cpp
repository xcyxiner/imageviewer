
#include <QImage>
#include <QImageReader>

#include "imageview.h"

#include "qgraphicsview.h"
#include "qhashfunctions.h"
#include "qimage.h"
#include "qnamespace.h"
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

void imageview::resizeEvent(QResizeEvent* event)
{
  QGraphicsView::resizeEvent(event);
  fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}
