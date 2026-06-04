
#include <QImage>
#include <QImageReader>

#include "imageview.h"

#include "qgraphicsview.h"
#include "qhashfunctions.h"
#include "qimage.h"
#include "qnamespace.h"
#include "qpixmap.h"
#include "qtmetamacros.h"

imageview::imageview(QWidget* parent)
    : QGraphicsView(parent)
{
  scene = new QGraphicsScene(this);

  setScene(scene);

  item = new QGraphicsPixmapItem();
  scene->addItem(item);

  setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
  setFocusPolicy(Qt::StrongFocus);
  setDragMode(QGraphicsView::ScrollHandDrag);
}

void imageview::resizeEvent(QResizeEvent* event)
{
  QGraphicsView::resizeEvent(event);
  fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

void imageview::loadImage(const QString& path)
{
  QImageReader reader(path);
  reader.setAutoTransform(true);
  QImage img = reader.read();

  if (img.isNull()) {
    return;
  }

  this->item->setPixmap(QPixmap::fromImage(img));

  scene->setSceneRect(item->boundingRect());
  fitInView(item->boundingRect(), Qt::KeepAspectRatio);
}

void imageview::keyPressEvent(QKeyEvent* event)
{
  emit this->keyHandle(event);
  QGraphicsView::keyPressEvent(event);
}

void imageview::wheelEvent(QWheelEvent* event)
{
  if (event->angleDelta().y() > 0) {
    zoomin();
  } else {
    zoomout();
  }
}

void imageview::zoomin()
{
  scale(1.15, 1.15);
}

void imageview::zoomout()
{
  scale(0.85, 0.85);
}

void imageview::fitview()
{
  fitInView(item->boundingRect(), Qt::KeepAspectRatio);
}

void imageview::resetview()
{
  resetTransform();
}
