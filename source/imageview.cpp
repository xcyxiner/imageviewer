
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

  item = new QGraphicsPixmapItem();
  scene->addItem(item);
}

void imageview::resizeEvent(QResizeEvent* event)
{
  QGraphicsView::resizeEvent(event);
  fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

void imageview::loadImage(const QString& path)
{
  QImageReader reader(path);
  QImage img = reader.read();

  if (img.isNull()) {
    return;
  }

  this->item->setPixmap(QPixmap::fromImage(img));

  scene->setSceneRect(item->boundingRect());
  fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}
