#include "playercontroller.h"

#include <iostream>


PlayerController::PlayerController()    : mPlayer()
                                        , mDataInspector()
                                        , mGtkThreadt(startGtkLoop)
{
    //void( fPtt)();
    //fPtt = startGtkLoop;
    //std::thread mGtkThreadt(startGtkLoop);

    //t.join();
    initGstreamer();

    mPlayer.init();
    mDataInspector.init();
}

void PlayerController::initGstreamer()
{
    std::cout<<"PlayerController::initGstreamer"<<std::endl;
    GError *error = NULL;
    if(!gst_is_initialized())
    {
        if(!gst_init_check(NULL, NULL, &error))
        {
            std::cout<<"Could Not Init GST. Error:  "<<error->message<<std::endl;
            return;
        }
        else
        {
            std::cout<<"GST has been inited"<<std::endl;
        }
    }

    std::cout<<gst_version_string()<<std::endl;
}

PlayerController::~PlayerController()
{
    mGtkThreadt.detach();
}

void PlayerController::play_request(const std::string& play)
{
    std::cout<<"PlayerController::play_request"<<std::endl;

    //mDataInspector.discover(play);
    mPlayer.play(play);
}

void PlayerController::startGtkLoop()
{
    std::cout<<"PlayerController::startGtkLoop"<<std::endl;
    g_main_loop_run(g_main_loop_new (NULL, FALSE));
}
