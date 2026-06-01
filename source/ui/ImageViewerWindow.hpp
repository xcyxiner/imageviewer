#ifndef IMAGEVIEWER_WINDOW_HPP
#define IMAGEVIEWER_WINDOW_HPP

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>

class ImageViewerWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit ImageViewerWindow(QWidget* parent = nullptr);

protected:
  void resizeEvent(QResizeEvent* event) override;

private:
  QGraphicsView* view_;
  QGraphicsScene* scene_;
  QGraphicsPixmapItem* pixmapItem_;
  void setupUi();
};

#endif  // IMAGEVIEWER_WINDOW_HPP
