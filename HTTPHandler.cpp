#include "HTTPHandler.h"
#include <iostream>
#include <QDataStream>

#define TIMER_MS    250


using namespace std;
HTTPHandler::HTTPHandler()
{
    // 네트워크 연결 관리
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), &connection_loop, SLOT(quit()));

    checkTimer = new QTimer(this);
    connect(checkTimer, SIGNAL(timeout()), this, SLOT(onCheck()));
    checkTimer->start(TIMER_MS);

}

// 공통적으로 사용되는 POST 구문 : 출력으로 응답 정보를 보냄
QByteArray HTTPHandler::generalPost(QByteArray post_data, QString url){
    QByteArray postDataSize = QByteArray::number(post_data.size());

    emit post_out();
    QUrl serviceURL(url);
    QNetworkRequest request(serviceURL);
//    qDebug() << serviceURL;
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setRawHeader("Content-Length", postDataSize);
    request.setRawHeader("Connection", "Keep-Alive");
    request.setRawHeader("AcceptEncoding", "gzip, deflate");
    request.setRawHeader("AcceptLanguage", "ko-KR,en,*");

    QNetworkReply *reply = manager->post(request, post_data);
    connection_loop.exec();

    reply->waitForReadyRead(200);
    QByteArray ret = reply->readAll();
    reply->deleteLater();
//    qDebug() << ret;// << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
    return ret;
}

void HTTPHandler::get_api_token(){
    QString server = "https://kakaoapi.aligo.in/akv10/token/create/30/s/";
    ClearJson(json_out);

    json_out["apikey"] = info.api_key;
    json_out["userid"] = info.user_id;

    QString postData = JsonToPost(json_out);
    QByteArray post_string = postData.toUtf8();

    QByteArray ret = generalPost(post_string, server);
    json_in = QJsonDocument::fromJson(ret).object();

    if(json_in["code"].toInt() == 0){
        info.token = json_in["token"].toString();
        info.urlencode = json_in["urlencode"].toString();
    }else{
        info.token = "";
        info.urlencode = "";
    }

    emit reply_in();


}

void HTTPHandler::get_templete(){
    QString server = "https://kakaoapi.aligo.in/akv10/template/list/";
    ClearJson(json_out);

    json_out["apikey"] = info.api_key;
    json_out["userid"] = info.user_id;
    json_out["token"] = info.token;
    json_out["senderkey"] = info.sender_key;
    json_out["tpl_code"] = "TJ_3357";

    QString postData = JsonToPost(json_out);
    QByteArray post_string = postData.toUtf8();

    QByteArray ret = generalPost(post_string, server);
    json_in = QJsonDocument::fromJson(ret).object();

    if(json_in["code"].toInt() == 0){
        QJsonObject json_list = json_in["list"].toArray()[0].toObject();
        info.templete_str = json_list["templtContent"].toString();
    }else{
        info.templete_str = "";
    }

    emit reply_in();

}


QString HTTPHandler::set_templete(QString platform, QString manager, QStringList error_list){
    if(info.templete_str != ""){
        QString templete_str = info.templete_str;

        qDebug() << "ORIGIN : " << templete_str;

        //Parsing (Find Variable)
        int index = templete_str.indexOf("#{매장명}",Qt::CaseSensitive);
        templete_str.remove(index, 6);

//        qDebug() << "REMOVE : " << templete_str;

        templete_str.insert(index,platform);

//        qDebug() << "INSERT : " << templete_str;



        //Parsing (Find Variable)
        index = templete_str.indexOf("#{고객명}",Qt::CaseSensitive);
        templete_str.remove(index, 6);
        templete_str.insert(index,manager);

//        qDebug() << "INSERT : " << templete_str;
        //Parsing (Find Variable)
        index = templete_str.indexOf("#{에러목록}",Qt::CaseSensitive);
        templete_str.remove(index, 7);
        for(int i=0; i<error_list.size(); i++){
            templete_str.insert(index, error_list[i]+"\n");
        }
        qDebug() << "INSERT : " << templete_str;
        return templete_str;
    }
    return "";
}

QByteArray HTTPHandler::generalGet(QString url){
    QUrl serviceURL(url);
    QNetworkRequest request(serviceURL);
    request.setRawHeader("Accept","application/vnd.github+json");
//    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
//    request.setRawHeader("Connection", "Keep-Alive");
//    request.setRawHeader("AcceptEncoding", "gzip, deflate");
//    request.setRawHeader("AcceptLanguage", "ko-KR,en,*");

    QNetworkReply *reply = manager->get(request);
    connection_loop.exec();

    reply->waitForReadyRead(200);
    QByteArray ret = reply->readAll();
    reply->deleteLater();
    return ret;
}


void HTTPHandler::testGit(){
    QString server = "https://api.github.com/repos/yuuujinHeo/UI_MOBILE/commits";
    ClearJson(json_out);
    QByteArray ret = generalGet(server);
//    qDebug() << ret;

    tt = QJsonDocument::fromJson(ret);
    QJsonArray test = tt.array();
    for(int i=0; i<test.size(); i++){
        QJsonObject temp = test[i].toObject();
        qDebug() << temp["commit"].toObject()["message"] << temp["commit"].toObject()["author"].toObject()["date"];
    }
//    qDebug() << tt["url"].toObject();
//    json_in = QJsonDocument::fromBinaryData(ret).object();
//    json_in = QJsonDocument::fromJson(ret).object();
//    qDebug() << json_in;
    emit reply_in();
}


void HTTPHandler::send_alimtalk(QString platform, QString manager, QStringList error_list){
    QString server = "https://kakaoapi.aligo.in/akv10/alimtalk/send/";
    ClearJson(json_out);

    json_out["apikey"] = info.api_key;
    json_out["userid"] = info.user_id;
    json_out["token"] = info.token;
    json_out["senderkey"] = info.sender_key;
    json_out["tpl_code"] = "TJ_3357";
    json_out["sender"] = info.sender_call;
    json_out["receiver_1"] = info.receiver_call;
    json_out["subject_1"] = info.subject;
    json_out["message_1"] = set_templete(platform, manager, error_list);

    QString postData = JsonToPost(json_out);
    QByteArray post_string = postData.toUtf8();

    QByteArray ret = generalPost(post_string, server);
    json_in = QJsonDocument::fromJson(ret).object();

    if(json_in["code"].toInt() == 0){
        qDebug() << "sending success !!!!!!!!!!!!!";
    }else{
        qDebug() << "sending Fail !!!!!!!!!!!!!!!!";
    }

    emit reply_in();
}

void HTTPHandler::onCheck(){
    static int connection_cnt = 0;
    static int cnt = 0;

}

void HTTPHandler::ClearJson(QJsonObject &json){
    QStringList keys = json.keys();
    for(int i=0; i<keys.size(); i++){
        json.remove(keys[i]);
    }
}

QString HTTPHandler::JsonToPost(QJsonObject json){
    QStringList keys = json.keys();
    QString postData = "";
    for(int i=0; i<keys.size(); i++){
        if(i!=0){
            postData += "&";
        }
        postData += keys[i];
        postData += "=";
        postData += json[keys[i]].toString();
    }

    return postData;
}
