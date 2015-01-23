#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>

class Controller : public QObject
{
     Q_OBJECT
public:
    Controller();
    ~Controller();
public slots:
    void play_request(std::string path);
};

#endif // CONTROLLER_H
