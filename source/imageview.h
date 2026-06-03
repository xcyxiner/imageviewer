
#pragma once
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>

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

signals:
  void keyHandle(QKeyEvent* event);

private:
  QGraphicsScene* scene;
  QGraphicsPixmapItem* item;
};
