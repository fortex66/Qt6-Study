#include "mainwindow.h"
#include <QAction>
#include <QDebug>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QListWidget>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenu *fileMenu;

    QAction *newAct;
    QAction *openAct;

    newAct = new QAction(QIcon(":/resources/pollution.png"), tr("New"), this);
    newAct->setShortcut(QKeySequence::New);
    newAct->setStatusTip("Create a new file");
    connect(newAct, SIGNAL(triggered()), this, SLOT(slot_newFile()));

    openAct = new QAction(QIcon(":/resources/tank.png"), tr("Open"), this);
    openAct->setShortcut(QKeySequence::Open);
    openAct->setStatusTip("Create a open file");
    connect(openAct, SIGNAL(triggered()), this, SLOT(slot_open()));

    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);

    QToolBar *fileToolBar;
    fileToolBar = addToolBar("File");
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);

    QDockWidget *dock = new QDockWidget("Target", this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    QListWidget *customerList = new QListWidget();

    QStringList list;
    list << "One" << "Two" << "Three" << "Four" << "Five";
    customerList->addItems(list);

    dock->setWidget(customerList);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    QMdiArea *area = new QMdiArea();
    area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QMdiSubWindow *subWindow1 = new QMdiSubWindow();
    subWindow1->resize(300,200);

    QPushButton *btn = new QPushButton("Button");
    subWindow1->setWidget(btn);

    QMdiSubWindow *subWindow2 = new QMdiSubWindow();
    subWindow2->resize(300,200);

    area->addSubWindow(subWindow1);
    area->addSubWindow(subWindow2);

    setCentralWidget(area);

}

void MainWindow::slot_newFile(){
    qDebug() << Q_FUNC_INFO;
}

void MainWindow::slot_open(){
    qDebug() << Q_FUNC_INFO;
}

MainWindow::~MainWindow() {}
