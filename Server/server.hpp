#ifndef SERVER_HPP
#define SERVER_HPP

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QTime>
#include <QHash>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server();
    QTcpSocket* socket;

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead(); // Handler for messige from client

private:
    void SendToClient(QString message, QString userFrom, QString userColor);

    QVector <QTcpSocket*> Sockets;
    QByteArray Data;

};

#endif // SERVER_HPP
