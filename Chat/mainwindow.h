#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "client.hpp"

#include <QMainWindow>
#include <QTcpSocket>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum THEME_MODE{ LIGHT, DARK };

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setBg(const THEME_MODE);
    QString getClientName();
    bool usernameChceker(const QString username);

private slots: // UI
    void on_connectButton_clicked();

    void on_themeButton_clicked();

    void on_lineEditReturn_pressed();

    void on_sendButton_clicked();

private:

    Ui::MainWindow *ui;
    Client* client;
    THEME_MODE m_theme{LIGHT};
};

#endif // MAINWINDOW_H
