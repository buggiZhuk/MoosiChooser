#include "player.h"
#include <iostream>
#include "gststreemdiscoverer.h"

Player::Player()
{

}

void Player::play(std::string &path)
{
    GstStreemDiscoverer discoverer;
    discoverer.discover(path);
    std::cout<<"Player::play"<<std::endl;
    g_object_set (mSource, "location", path.c_str(), NULL);
    GstStateChangeReturn ret = gst_element_set_state (mPipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE)
    {
        std::cout<<"!!!!!!!!"<<std::endl;
        g_printerr ("Unable to set the pipeline to the playing state.\n");
    }
    else
    {
        std::cout<<"state changed"<<std::endl;
        g_object_set(mSink, "ts-offset", 3000000000, NULL);
    }

}

bool  Player::init()
{
    GError *error = NULL;
    if(!gst_is_initialized())
    {
        if(!gst_init_check(NULL, NULL, &error))
        {
            std::cout<<"Could Not Init GST. Error:  "<<error->message<<std::endl;
            return false;
        }
    }

    /**
     * @brief TODO:
     * remove ugly singletone;
     */
    static bool loopStarted = false;
    if(!loopStarted)
    {
        pthread_t thread1;
        int iret1 = pthread_create( &thread1, NULL, startGtkLoop, NULL);
        if(iret1)
        {
            fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
            return false;
        }

        loopStarted = true;
    }

    std::cout<<gst_version_string();

    mPipeline = gst_pipeline_new ("buggiPipeline");
    mSource = gst_element_factory_make ("filesrc", "source");
    mConvert = gst_element_factory_make ("mad", "convert");
    mSink = gst_element_factory_make ("autoaudiosink", "sink");


    if (!mSource || !mConvert|| !mSink || !mPipeline ) {
        g_printerr ("Not all elements could be created.\n");
        return -1;
      }

    gst_bin_add_many (GST_BIN (mPipeline), mSource, mConvert , mSink,  NULL);
    gst_element_link_many (mSource, mConvert, mSink, NULL);

    GstBus *bus = gst_pipeline_get_bus(GST_PIPELINE(mPipeline));
    gst_bus_add_signal_watch (bus);
    g_signal_connect(bus, "message::state-changed", G_CALLBACK(&state_changed_cb), this);

    return true;

}

void Player::state_changed_cb (GstBus *bus, GstMessage *msg, Player *data)
{
  GstState old_state, new_state, pending_state;
  gst_message_parse_state_changed (msg, &old_state, &new_state, &pending_state);
  if (GST_MESSAGE_SRC (msg) == GST_OBJECT (data->mPipeline))
  {
      std::cout<<"state of pipeline has been changed"<<std::endl;
  }
}

void* Player::startGtkLoop(void*)
{
    std::cout<<"!!!!!!!!!"<<std::endl;
    g_main_loop_run(g_main_loop_new (NULL, FALSE));
    std::cout<<"!!!!!!!!!"<<std::endl;
    return 0;
}
Player& Player::getInstance()
{
    /**
     * @brief ugly singleton, should be rewritten
     */
    static Player *pl = new Player;
    static bool is_inited = false;
    if(!is_inited)
    {
        pl->init();
        is_inited = true;
    }
    return *pl;
}
Player::~Player()
{
    std::cout<<"Player::~Player";
    //gst_element_set_state (mPipeline, GST_STATE_NULL);
    //gst_object_unref (mPipeline);
}

