#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pHTTP = new HTTPHandler();

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
    timer->start(100);

    connect(pHTTP, SIGNAL(post_out()),this,SLOT(set_Out()));
    connect(pHTTP, SIGNAL(reply_in()),this,SLOT(set_In()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimer(){
    ui->LE_TOKEN->setText(pHTTP->info.token);
}
void MainWindow::on_BTN_GET_TOKEN_clicked()
{
    pHTTP->testGit();
//    pHTTP->get_api_token();
}

void MainWindow::on_BTN_GET_TEMPLETE_clicked()
{
    pHTTP->get_templete();
}

void MainWindow::set_Out(){
    ui->TE_POST->setText(QJsonDocument(pHTTP->json_out).toJson(QJsonDocument::Indented));
}
void MainWindow::set_In(){
    ui->TE_REPLY->setText(pHTTP->tt.toJson(QJsonDocument::Indented));//QJsonDocument(pHTTP->json_in).toJson(QJsonDocument::Indented));
}

void MainWindow::on_BTN_SET_TEMPLETE_clicked()
{
    QStringList error_list;
    if(ui->LE_ERROR_1->text() != "")
        error_list.push_back(ui->LE_ERROR_1->text());

    if(ui->LE_ERROR_2->text() != "")
        error_list.push_back(ui->LE_ERROR_2->text());

    if(ui->LE_ERROR_3->text() != "")
        error_list.push_back(ui->LE_ERROR_3->text());

    pHTTP->info.receiver_call = ui->LE_RECEIVER->text();
    pHTTP->send_alimtalk(ui->LE_PLATFORM->text(),ui->LE_MANAGER->text(),error_list);
}
