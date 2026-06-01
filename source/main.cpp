#include <QApplication>

#include "mainwindow.h"

auto main(int argc, char** argv) -> int
{
  QApplication app(argc, argv);
  auto* mw = new mainwindow();
  mw->show();
  return app.exec();
}
