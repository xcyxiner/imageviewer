
#pragma once
#include <QDir>
#include <QMainWindow>

#include "imageview.h"
#include "qfileinfo.h"
#include "qglobal.h"
#include "qkeysequence.h"

class mainwindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit mainwindow(QWidget* parent = nullptr);

private:
  void createMenu();
  void openFolderAndShow(const QString& path);
  void showCurrentImage();
  imageview* view;
  QDir dir;
  QStringList m_files;
  int m_current_index;
};
