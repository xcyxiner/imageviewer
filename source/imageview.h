
#pragma once
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "qgraphicsscene.h"
#include "qobject.h"

class imageview : public QGraphicsView
{
  Q_OBJECT
public:
  explicit imageview(QWidget* parent = nullptr);

public:
  void resizeEvent(QResizeEvent* event) override;
  void loadImage(const QString& path);

private:
  QGraphicsScene* scene;
  QGraphicsPixmapItem* item;
};
