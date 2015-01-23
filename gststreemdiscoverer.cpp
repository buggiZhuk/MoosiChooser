#include "gststreemdiscoverer.h"
#include <iostream>
GstStreemDiscoverer::GstStreemDiscoverer()
{
    //gst_pb_utils_init() ;
    GError *err = NULL;
    //mDiscoverer = gst_discoverer_new (5 * GST_SECOND, &err);
    if (!mDiscoverer) {
    std::cout<<"Error creating discoverer instance:"<<err->message<<std::endl;
        g_clear_error (&err);
        return;
      }
}

void GstStreemDiscoverer::discover(std::string &path)
{

}

GstStreemDiscoverer::~GstStreemDiscoverer()
{

}

