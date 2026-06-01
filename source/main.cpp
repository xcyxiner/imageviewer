#include <QApplication>

#include "ui/ImageViewerWindow.hpp"

auto main(int argc, char** argv) -> int
{
  QApplication app(argc, argv);

  ImageViewerWindow w;
  w.show();

  return app.exec();
}
