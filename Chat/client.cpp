#include "client.hpp"

#include <QTime>


QString randomColor()
{
    QString colors[7] = { "#0996f5", "#Ff0003", "#E87479", "#00ff35", "#750b6c", "#Ff00f1", "#001bff"};
    int random = rand() % 7;

    QString tempColor = colors[random];

    colors->replace(colors[colors->size()], colors[random]);
    colors->remove(colors[colors->size()]);
    return tempColor;

    /*switch (random) {

    case 0: return "#0996f5";   // Azure Radiance
    case 1: return "#Ff0003";   // Red
    case 2: return "#E87479";   // Sunglo
    case 3: return "#00ff35";   // Green
    case 4: return "#750b6c";   // Rose Bud Cherry
    case 5: return "#Ff00f1";   // Magenta
    case 6: return "#001bff";   // Blue
    }*/
}

Client::Client(const QString clientName, Ui::MainWindow* ui)
    : m_clientName(clientName)
    , m_ui(ui)
{
    m_clientNameColor = randomColor();
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &Client::SlotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
}

void Client::SlotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);

    if(in.status() == QDataStream::Ok) {
        QString message, sender, senderColor;
        QTime time;
        in >> sender >> senderColor >> time >> message;
        sender = QString("<span style=\" color:" + senderColor + "; \">%1</span>").arg(sender);
        m_ui->textBrowser->append(sender + ": ");
        m_ui->textBrowser->append("   " + message + "\t\t\t" + time.toString());
        m_ui->textBrowser->backward();

    } else {
        m_ui->textBrowser->append("Read Error");
    }
}

void Client::SendToServer(QString message)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << m_clientName << m_clientNameColor << QTime::currentTime() << message;

    socket->write(Data);
    m_ui->lineEdit->clear();
}

void Client::ConnectToServer()
{
    socket->connectToHost("127.0.0.1", 2323); // IP Address and Port
}
