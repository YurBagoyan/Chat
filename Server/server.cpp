#include "server.hpp"
#include <QDataStream>

Server::Server()
{
    if(this->listen(QHostAddress::Any, 2323)) { // If Server connected
        qDebug() << "Server started";
    } else {
        qDebug() << "ERROR";
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    socket->objectName();

    qDebug() << "Client " << socketDescriptor << " connected!";
}

void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);

    in.setVersion(QDataStream::Qt_6_4);

    if(in.status() == QDataStream::Ok) {
        qDebug() << "Reading message...";

        QString message, sender, senderColor;
        QTime time;
        in >> sender >> senderColor >> time >> message;
        qDebug() << "Sender = " << sender << " -> " << message;
        SendToClient(message, sender, senderColor);

    } else {
        qDebug() << "Data Stream ERROR";
    }

}

void Server::SendToClient(QString message, QString userFrom, QString userColor)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << userFrom << userColor << QTime::currentTime() << message;

    // Send messige to all sockets
    for(int i = 0; i < Sockets.size(); ++i) {
        Sockets[i]->write(Data);
    }
}
