#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "ui_mainwindow.h"
#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    Client(const QString clientName, Ui::MainWindow* ui);

public slots:
    void SlotReadyRead();
    void SendToServer(QString message);
    void ConnectToServer();

private:
    QString m_clientName;
    Ui::MainWindow* m_ui;

    QString m_clientNameColor;

    QTcpSocket* socket;
    QByteArray Data;

};

#endif // CLIENT_HPP
