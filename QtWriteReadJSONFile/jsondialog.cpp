#include "jsondialog.h"
#include "ui_jsondialog.h"

JsonDialog::JsonDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::JsonDialog)
{
    ui->setupUi(this);
    connect(ui->writeJSONBtn,&QPushButton::clicked,this,&JsonDialog::SlotWriteJSONFile);
    connect(ui->readJSONBtn,&QPushButton::clicked,this,&JsonDialog::SlotReadJSONFile);
}

JsonDialog::~JsonDialog()
{
    delete ui;
}

void JsonDialog::SlotWriteJSONFile()
{
    //1.创建JSON对象
    QJsonObject mysql_info;
    mysql_info.insert("ip","127.0.0.1");
    mysql_info.insert("port",3386);
    mysql_info.insert("user","root");
    mysql_info.insert("password","123456");

    QJsonObject json_info;
    json_info.insert("code",1);
    json_info.insert("dbmsg","MySQL数据库配置参数");
    json_info.insert("data",mysql_info);

    //2.创建JSON文档
    QJsonDocument jsondoc;
    jsondoc.setObject(json_info);

    //3.创建文件
    QFile file("./dbjsonfile.json");
    if(file.open(QIODevice::WriteOnly)){
        file.write(jsondoc.toJson());
        file.close();
        QMessageBox::information(this,tr("成功"),tr("恭喜你,json数据写入成功"),QMessageBox::Ok);
    }
}

void JsonDialog::SlotReadJSONFile()
{
    QString str_json;
    QString msg;
    QFile file("./dbjsonfile.json");
    if(file.open(QIODevice::ReadOnly)){
        str_json = file.readAll();
        file.close();
    }
    QJsonParseError json_parse_error;
    QJsonDocument json_doc = QJsonDocument::fromJson(str_json.toUtf8(),&json_parse_error);
    if(!(json_doc.isEmpty()) && (json_parse_error.error == QJsonParseError::NoError)){
        //解析json无错误则将其转换成json对象
        QJsonObject json = json_doc.object();
        QJsonValue code = json.value("code");
        QJsonValue data = json.value("data");
        if(code.isUndefined() || code.toDouble() != 1 || data.isUndefined() || !data.isObject()){
            qDebug() << "转换json数据失败，重新检查json文件。";
            QMessageBox::information(this,tr("失败提示"),tr("json数据读取失败！！！"),QMessageBox::Close);
            exit(100);
        }
        //如果解析json数据成功,读取data数据信息
        QJsonObject dbinfo = data.toObject();
        QJsonValue dbip = dbinfo.value("ip");
        QJsonValue dbport = dbinfo.value("port");
        QJsonValue dbuser = dbinfo.value("user");
        QJsonValue dbpassword = dbinfo.value("password");
        //检查数据是否正确
        if(dbip.isUndefined() ||
            dbport.isUndefined() ||
            dbuser.isUndefined() ||
            dbpassword.isUndefined()){
            qDebug() << "转换json数据失败，重新检查json文件。";
            QMessageBox::information(this,tr("失败提示"),tr("json数据读取失败！！！"),QMessageBox::Close);
            exit(100);
        }
        QString str_ip = dbip.toString();
        int port = dbport.toInt();
        QString str_user = dbuser.toString();
        QString str_password = dbpassword.toString();
        //检查是否为空
        if(str_ip.isEmpty() || str_user.isEmpty() || str_password.isEmpty()){
            qDebug() << "此数据不能为空，重新检查json文件。";
            QMessageBox::information(this,tr("失败提示"),tr("此数据不能为空，重新检查json文件。"),QMessageBox::Close);
            exit(100);
        }
        qDebug() << "数据库IP地址："<<str_ip.toUtf8().data();
        qDebug() << "数据库PORT："<<port;
        qDebug() << "数据库用户名："<<str_user.toUtf8().data();
        qDebug() << "数据库密码："<<str_password.toUtf8().data();
        msg += "数据库IP地址：" + str_ip \
               +"\n数据库PORT：" + QString::number(port) \
               +"\n数据库用户名：" + str_user + \
                 "\n数据库密码："+str_password;
    }
    QMessageBox::information(this,"json配置信息",msg,QMessageBox::Yes);
}
