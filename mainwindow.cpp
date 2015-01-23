#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <gst/gst.h>
#include "test.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    emit play_request("/home/buggi/1.mp3");
}

void MainWindow::on_pushButton_2_clicked()
{
    test tst;
    tst.tst();
}
