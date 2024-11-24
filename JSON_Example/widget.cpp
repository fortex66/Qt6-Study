#include "widget.h"
#include "ui_widget.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(pressed()), this , SLOT(slot_pbtParsing()));

}

void Widget::parseJSON(const QString &data)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data.toLocal8Bit());
    QJsonObject jsonObj = jsonResponse.object();

    QString timeStr = jsonObj["time"].toString();
    QString dateStr = jsonObj["date"].toString();

    QString successStr;
    if(jsonObj["success"].toBool() == true)
        successStr = QString("success : true");
    else
        successStr = QString("success : false");

    ui->textEdit->clear();

    ui->textEdit->append(timeStr);
    ui->textEdit->append(dateStr);
    ui->textEdit->append(successStr);

    QJsonArray jsonArray = jsonObj["properties"].toArray();
    foreach(const QJsonValue &value, jsonArray)
    {
        QJsonObject obj = value.toObject();
        int id = obj["ID"].toInt();
        QString property = obj["PropertyName"].toString();

        QString arrData = QString("ID : %1 , PropertyName : %2").arg(id).arg(property);
        ui->textEdit->append(arrData);
    }

}

void Widget::slot_pbtParsing()
{
    QFile file(":/simple.json");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString data = file.readAll();

    parseJSON(data);
}

Widget::~Widget()
{
    delete ui;
}
