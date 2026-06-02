
#include <QAction>
#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>

#include "mainwindow.h"

#include "qaction.h"
#include "qfiledialog.h"
#include "qkeysequence.h"

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
              this->view->loadImage(path);
            }
          });
}
