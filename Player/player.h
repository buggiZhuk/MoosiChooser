#ifndef PLAYER_H
#define PLAYER_H

#include <gst/gst.h>
#include <string>

/**
 * @brief TODO: add more detailed error handling. Player not only should log error, but also - report to master about them
 */

class Player
{
private:


private:
    GstElement *mSource;
    GstElement *mConvert;
    GstElement *mParse;
    GstElement *mSink;
    GstElement *mPipeline;
public:
    ~Player();
    /**
     * @brief init
     * @return
     * TODO: needde to be refactored. Should be called from constructor of object
     */
    bool init();

//interface
public:
    Player();
    void play(const std::string &path);
    void pause();
    void stop();

private:
    static void state_changed_cb (GstBus *bus, GstMessage *msg, Player *data);
    static void error_cb (GstBus *bus, GstMessage *msg, Player *data);

};

#endif // PLAYER_H
