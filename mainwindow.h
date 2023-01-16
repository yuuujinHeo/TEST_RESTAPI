#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "HTTPHandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onTimer();
    void set_Out();
    void set_In();
    void on_BTN_GET_TOKEN_clicked();

    void on_BTN_GET_TEMPLETE_clicked();

    void on_BTN_SET_TEMPLETE_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    HTTPHandler  *pHTTP;
};
#endif // MAINWINDOW_H
