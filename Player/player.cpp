#include "player.h"
#include <iostream>
//#include "Player/gststreemdiscoverer.h"

Player::Player()    : mSource(NULL)
                    , mConvert(NULL)
                    , mParse(NULL)
                    , mSink(NULL)
                    , mPipeline(NULL)
{
}

void Player::play(const std::string &path)
{
    //GstStreemDiscoverer discoverer;
    //discoverer.discover(path);
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
    }

}

bool  Player::init()
{
    mPipeline   = gst_pipeline_new ("buggiPipeline");
    mSource     = gst_element_factory_make ("filesrc", "source");
    mConvert    = gst_element_factory_make ("mad", "convert");
    //mParse = gst_element_factory_make ("flacparse", "flacparse");
    //mConvert = gst_element_factory_make ("flacdec", "flacdec");
    mSink = gst_element_factory_make ("autoaudiosink", "sink");


    if (!mSource || !mConvert|| !mSink || !mPipeline ) {
        g_printerr ("Not all elements could be created.\n");
        return -1;
      }

    gst_bin_add_many (GST_BIN (mPipeline), mSource, mConvert , mSink,  NULL);
    if(gst_element_link_many (mSource,  mConvert, mSink, NULL) != TRUE) {
        std::cout<<"!!!! could not link elements!!!!"<<std::endl;
    }
    else
    {
        std::cout<<"elements has been linked"<<std::endl;
    }

    GstBus *bus = gst_pipeline_get_bus(GST_PIPELINE(mPipeline));
    gst_bus_add_signal_watch (bus);
    g_signal_connect(bus, "message::state-changed", G_CALLBACK(&state_changed_cb), this);
    g_signal_connect(bus, "message::error", G_CALLBACK(&error_cb), this);

    return true;

}

void Player::error_cb (GstBus *bus, GstMessage *msg, Player *data)
{
    GError *err;
    gchar *debug_info;
    gst_message_parse_error (msg, &err, &debug_info);
    err->code;
    std::cout<<gst_error_get_message (err->domain, err->code)<<std::endl;
              g_printerr ("Error received from element %s: %s\n", GST_OBJECT_NAME (msg->src), err->message);
              g_printerr ("Debugging information: %s\n", debug_info ? debug_info : "none");
              g_clear_error (&err);
    std::cout<<"ERROR"<<std::endl;
}

static gboolean
cb_print_position (GstElement *pipeline)
{
  gint64 pos, len;

  GstFormat fmt = GST_FORMAT_TIME;
  if (gst_element_query_position (pipeline, &fmt, &pos)
    && gst_element_query_duration (pipeline, &fmt, &len)) {
    g_print ("Time: %" GST_TIME_FORMAT " / %" GST_TIME_FORMAT "\r",
         GST_TIME_ARGS (pos), GST_TIME_ARGS (len));
  }

  /* call me again */
  return TRUE;
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

Player::~Player()
{
    std::cout<<"Player::~Player";
    gst_element_set_state (mPipeline, GST_STATE_NULL);
    gst_object_unref (mPipeline);
}

