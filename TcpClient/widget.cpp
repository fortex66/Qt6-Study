#include "widget.h"
#include "ui_widget.h"

#include <QHostAddress>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    initialize();
}

void Widget::initialize()
{
    setWindowTitle("TCP 클라이언트");
    connect(ui->pbtConn, SIGNAL(clicked(bool)), this, SLOT(slot_connectBtn()));

    m_tcpSocket = new QTcpSocket(this);
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(slot_readMessage()));
    connect(m_tcpSocket, SIGNAL(disconnected()), this, SLOT(slot_disconnected()));
}

void Widget::slot_connectBtn()
{
    QString serverIP = ui->leServerIP->text().trimmed();

    QHostAddress serverAddr(serverIP);
    m_tcpSocket->connectToHost(serverAddr, 25000);
}

void Widget::slot_readMessage()
{
    if(m_tcpSocket->bytesAvailable() >= 0){
        QByteArray readData = m_tcpSocket->readAll();
        ui->textEdit->append(readData);
    }
}

void Widget::slot_disconnected()
{
    ui->textEdit->append("서버와 접속이 종료됨.");
}

Widget::~Widget()
{
    delete ui;
}
