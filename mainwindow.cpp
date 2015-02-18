#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <gst/gst.h>
#include <qabstractitemmodel.h>
#include <qstringlistmodel.h>
#include <qstringlist.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList numbers;
    numbers << "One" << "Two" << "Three" << "Four" << "Five";

    QAbstractItemModel *model = new QStringListModel(numbers);
    //ui->songsView->setModel(model);
    //ui->songsView->setSelectionMode(QAbstractItemView::SingleSelection);
    /*ui->songsView->setDragEnabled(true);
    ui->songsView->viewport()->setAcceptDrops(true);
    ui->songsView->setDropIndicatorShown(true);
    ui->songsView->setModelColumn(1);*/
    //ui->songsView->setDefaultDropAction(Qt::DropAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    emit play_request("/home/buggi/1.mp3");
}
