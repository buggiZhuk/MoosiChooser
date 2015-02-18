#include "mainwindow.h"
#include "Player/playercontroller.h"
#include <QApplication>
#include <string>
#include <map>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout<<argv[0]<<std::endl;
    QApplication a(argc, argv);
    MainWindow w;
    PlayerController controller;
    QObject::connect(&w, SIGNAL(play_request(std::string)),  &controller, SLOT(play_request(std::string)));
    w.show();

    return a.exec();
}

int fn1()
{
    std::cout<<"fn1"<<std::endl;
    return 0;
}

void fn2(int par)
{
    std::cout<<"fn2 par = "<<par<<std::endl;
}
