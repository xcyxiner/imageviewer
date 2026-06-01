#include "ui/ImageViewerWindow.hpp"

#include <QImageReader>
#include <QPixmap>
#include <QPainter>
#include <QScreen>
#include <QApplication>
#include <QResizeEvent>

ImageViewerWindow::ImageViewerWindow(QWidget* parent)
  : QMainWindow(parent),
    view_(new QGraphicsView(this)),
    scene_(new QGraphicsScene(this)),
    pixmapItem_(new QGraphicsPixmapItem())
{
  setupUi();
}

void ImageViewerWindow::setupUi()
{
  view_->setScene(scene_);
  scene_->addItem(pixmapItem_);

  // Remove scroll bar decorations per docs/v1
  view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  // Better rendering for pixmaps
  view_->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

  setCentralWidget(view_);

  // Placeholder: no business logic implemented (no image loading)
}

void ImageViewerWindow::resizeEvent(QResizeEvent* event)
{
  Q_UNUSED(event);
  // Keep image fitted to view while preserving aspect ratio. No-op if no pixmap set.
  if (!scene_->items().isEmpty()) {
    view_->fitInView(scene_->itemsBoundingRect(), Qt::KeepAspectRatio);
  }
}
