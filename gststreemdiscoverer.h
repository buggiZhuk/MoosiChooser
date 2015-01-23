#ifndef GSTSTREEMDISCOVERER_H
#define GSTSTREEMDISCOVERER_H

#include <gst/gst.h>
#include <gst/pbutils/pbutils.h>
#include <string>

class GstStreemDiscoverer
{
    GstDiscoverer *mDiscoverer;

public:
    GstStreemDiscoverer();
    ~GstStreemDiscoverer();

    void discover(std::string &path);
};

#endif // GSTSTREEMDISCOVERER_H
