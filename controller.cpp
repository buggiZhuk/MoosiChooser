#include "controller.h"
#include <iostream>
#include <player.h>
Controller::Controller()
{

}

Controller::~Controller()
{

}

void Controller::play_request(std::string path)
{
    Player::getInstance().play(path);
    std::cout<<"Controller::play_request "<<path<<std::endl;
}
