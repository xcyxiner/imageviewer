
#include "mainwindow.h"

#include "imageview.h"

mainwindow::mainwindow(QWidget* parent)
    : QMainWindow(parent)
{
  auto* view = new imageview(this);
  setCentralWidget(view);
}
