#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <QObject>
#include "networkclient.h"

class GameApp : public QObject
{
    Q_OBJECT
public:
    explicit GameApp(QObject *parent = 0);
    void run(QString name, QString server, QString port);

signals:
public slots:
    void endOfThread();
    void up();
    void changeCourse();

 private:
    NetworkClient * nc;
    int lastTarget;
    int dir;
};

#endif // GAMEAPP_H
