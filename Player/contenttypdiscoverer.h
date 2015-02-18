#ifndef CONTENTTYPDISCOVERER_H
#define CONTENTTYPDISCOVERER_H

#include "datatypes.h"
#include <gst/gst.h>
#include <gst/pbutils/pbutils.h>
#include <string>

class ContentTypeDiscoverer
{
    GstDiscoverer *mDiscoverer;
public:
    ContentTypeDiscoverer();
    ~ContentTypeDiscoverer();

    /**
      TODO:
      remove initializing to constructor
     * @brief init
     */
    void init();
    void discover(const std::string& path_in);
};

#endif // CONTENTTYPDISCOVERER_H
