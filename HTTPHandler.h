#ifndef HTTPHANDLER_H
#define HTTPHANDLER_H

#include <QObject>
#include <QtNetwork>
#include <QTimer>
#include <QDebug>

// json -----------------------
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

// connection ------------------
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QNetworkRequest>

// websocket ------------------
#include <websocket/QtHttpServer.h>
#include <websocket/QtHttpRequest.h>
#include <websocket/QtHttpReply.h>
#include <websocket/QtHttpHeader.h>

#define KIOSK_URL   "http://127.0.0.1:28081"

typedef struct _KAKAO_INFO_{

//    QString api_key = "plu1g0g47s0wz7ypxmvsw85xm5mf2np2";
    QString api_key = "8c5a64ccbcd01e107f4eccc83422dece";
    QString user_id = "blike4";
    QString sender_key = "bdaca9d57f59d51af2d90452c92b0241b55758d0";

    QString sender_call = "01020866685";
    QString receiver_call = "01020866685";
    QString subject = "ERROR";


    QString token = "";
    QString urlencode = "";

    QString templete_str = "";

}Kakao_info;

class HTTPHandler : public QObject
{
    Q_OBJECT

public:
    HTTPHandler();
    QByteArray generalPost(QByteArray post_data, QString url);
    QByteArray generalGet(QString url);

    void testGit();
    void set_user(QString api_key, QString user_id);
    void get_api_token();
    void get_templete();
    void send_alimtalk(QString platform, QString manager, QStringList error_list);

    QString set_templete(QString platform, QString manager, QStringList error_list);

    QJsonObject json_out;
    QJsonObject json_in;
    QJsonDocument tt;
    void ClearJson(QJsonObject &json);
    QString JsonToPost(QJsonObject json);

    Kakao_info info;

signals:
    void post_out();
    void reply_in();
public slots:
    void onCheck();

private:
    QTimer *checkTimer;
    // 네트워크 커넥션 관리 -----------------
    QNetworkAccessManager   *manager;
    QEventLoop              connection_loop;

};

#endif // HTTPHANDLER_H
