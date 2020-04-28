#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    view = new View(this);

    setMinimumSize(600, 300);
    //600 400
    setCentralWidget(view);

    menu = new Menu(this);
    setMenuBar(menu);
}

MainWindow::~MainWindow()
{
    delete view;
    delete menu;
}
