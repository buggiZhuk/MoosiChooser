#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "player.h"
#include "contenttypdiscoverer.h"
#include <QObject>
#include <thread>

class PlayerController: public QObject
{
    Q_OBJECT

    Player mPlayer;
    ContentTypeDiscoverer mDataInspector;
    std::thread mGtkThreadt;
    static void startGtkLoop();
public:
    PlayerController();
    virtual ~PlayerController();
    void initGstreamer();

public slots:
    void play_request(const std::string& play);
};

#endif // PLAYERCONTROLLER_H
