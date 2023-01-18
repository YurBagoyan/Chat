#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextBrowser>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowTitle("Chat");
    setBg(LIGHT);

    show();
    client = new Client(getClientName(), ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    qDebug()<<"Conncet Button clicked";
    client->ConnectToServer();
}

void MainWindow::on_lineEditReturn_pressed()
{
    client->SendToServer(ui->lineEdit->text());
}

void MainWindow::on_sendButton_clicked()
{
    qDebug()<<"Send Button clicked";
    client->SendToServer(ui->lineEdit->text());
}

void MainWindow::on_themeButton_clicked()
{
    qDebug() << " Theme Button clicked";

    if(m_theme == LIGHT) {
        setBg(DARK);
        return;
    }

    setBg(LIGHT);
}

void MainWindow::setBg(const THEME_MODE theme)
{
    QPalette* pal = new QPalette();

    if(theme == DARK) {
        ui->textBrowser->setStyleSheet("color: white; background-color: #404142");
        ui->lineEdit->setStyleSheet("color: white; background-color: #404142");
        pal->setColor(QPalette::Window, QColor(46,47,48));
        this->setPalette(*pal);

    }
    else {
        ui->textBrowser->setStyleSheet("background-color: #edf2f7");
        ui->lineEdit->setStyleSheet("background-color: #edf2f7");
        pal->setColor(QPalette::Window, QColor(179, 205, 232));
        this->setPalette(*pal);
    }

    m_theme = theme;
}

QString MainWindow::getClientName()
{
    QString username = "";
    QStringList tempList(0);
    bool okPressed = false;

    do {
        username = QInputDialog::getItem(this, "Username", "Please input your username", tempList, 0, true, &okPressed);

        if(okPressed && usernameChceker(username)) {
            qDebug() << username;
            return username;
        } else {
            // Cancel pressed

        }
    } while(true);
}

bool MainWindow::usernameChceker(const QString username)
{
    if(username.size() <= 0 || username.size() > 10) {
        return false;
    }

    bool result = false;
    for(int i = 0; i < username.size(); ++i) {
        if(username[i].isLetter()) {
            result = true;
        }
    }

    return result;
}
