
#pragma once
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWheelEvent>

#include "qgraphicsitem.h"
#include "qgraphicsscene.h"
#include "qobject.h"
#include "qtmetamacros.h"

class imageview : public QGraphicsView
{
  Q_OBJECT
public:
  explicit imageview(QWidget* parent = nullptr);

public:
  void resizeEvent(QResizeEvent* event) override;
  void loadImage(const QString& path);
  void keyPressEvent(QKeyEvent* event) override;
  void wheelEvent(QWheelEvent* event) override;
  void zoomin();
  void zoomout();
  void fitview();
  void resetview();

signals:
  void keyHandle(QKeyEvent* event);

private:
  QGraphicsScene* scene;
  QGraphicsPixmapItem* item;
};
