
#pragma once
#include <QMainWindow>

#include "imageview.h"

class mainwindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit mainwindow(QWidget* parent = nullptr);

private:
  void createMenu();
  imageview* view;
};
