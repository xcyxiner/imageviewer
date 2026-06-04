#include <QAction>
#include <QFileDialog>
#include <QKeyEvent>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>

#include "mainwindow.h"

#include "imageview.h"
#include "qaction.h"
#include "qdir.h"
#include "qfiledialog.h"
#include "qfileinfo.h"
#include "qgraphicsitem.h"
#include "qkeysequence.h"
#include "qnamespace.h"

mainwindow::mainwindow(QWidget* parent)
    : QMainWindow(parent)
{
  view = new imageview(this);
  setCentralWidget(view);
  this->createMenu();
}

void mainwindow::createMenu()
{
  auto* menu = menuBar()->addMenu("File");

  auto* action = new QAction("Open", this);

  action->setShortcut(QKeySequence::Open);
  menu->addAction(action);

  connect(action,
          &QAction::triggered,
          this,
          [this]
          {
            QString path = QFileDialog::getOpenFileName(
                this, "", QString(), "*.jpg *.png *.jpeg");
            if (!path.isNull()) {
              this->openFolderAndShow(path);
            }
          });

  connect(view,
          &imageview::keyHandle,
          this,
          [this](QKeyEvent* event)
          {
            if (event->key() == Qt::Key_Left) {
              m_current_index =
                  (m_current_index - 1 + m_files.size()) % m_files.size();
            } else if (event->key() == Qt::Key_Right) {
              m_current_index = (m_current_index + 1) % m_files.size();
            }
            showCurrentImage();
          });
  auto* toolbar = this->addToolBar("toolbar");
  auto* fitAction = new QAction("fit view", this);
  auto* actualAction = new QAction("actual view", this);

  toolbar->addAction(fitAction);
  toolbar->addAction(actualAction);

  connect(fitAction, &QAction::triggered, view, &imageview::fitview);
  connect(actualAction, &QAction::triggered, view, &imageview::resetview);
}

void mainwindow::openFolderAndShow(const QString& path)
{
  auto* info = new QFileInfo(path);
  this->dir = info->dir();
  this->m_files = dir.entryList(
      {"*.jpg", "*.png"}, QDir::Files | QDir::Readable, QDir::Name);
  this->m_current_index = m_files.indexOf(info->fileName());
  this->showCurrentImage();
}

void mainwindow::showCurrentImage()
{
  if (m_current_index < 0 || m_current_index >= m_files.size()) {
    return;
  }
  auto name = this->m_files.at(m_current_index);
  auto path = dir.filePath(name);
  this->view->loadImage(path);

  statusBar()->showMessage(
      QString("%1 / %2").arg(m_current_index + 1).arg(m_files.size()));
}
