#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include "model.h"
#include <QObject>
#include <QtNetwork>

class NetworkClient : public QObject
{
    Q_OBJECT
public:
    explicit NetworkClient(Model * mod,QObject *parent = 0);
    void send(QString mess);
    void setName(QString name);
    void startOn(QString host, qint16 port);
    void modifications(QList<QPair<QString, QVariant> > keys);
signals:
    void event();
public slots:
    void init();
    void err();
    void processIncommingData();
    void sendKeyState(QString name, bool state);
    void sendMouseState(float x, float y, float z);
    void sendShot(float x, float y, float z);

private:
    QTcpSocket * sock;
    QString name;
    QString messages;
    Model * m;
};

#endif // NETWORKCLIENT_H
