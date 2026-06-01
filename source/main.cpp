#include <QApplication>
#include <QGraphicsView>
#include <QMainWindow>
#include <iostream>
#include <string>

#include "lib.hpp"
#include "qapplication.h"

auto main(int argc, char** argv) -> int
{
  QApplication app(argc, argv);

  int ret = app.exec();
  return ret;
}
