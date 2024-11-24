#include "widget.h"
#include "ui_widget.h"

#include <QtWidgets>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    initialize();
}

void Widget::initialize()
{
    setWindowTitle("Tcp 서버");

    QHostAddress hostAddress;
    QList<QHostAddress> ipAddressList = QNetworkInterface::allAddresses(); // IP 전부다 가져오기
    for(int i = 0; i < ipAddressList.size(); i++)
    {
        // 아이피들 목록들 중 IPv4라면 hostAddress에 저장
        if(ipAddressList.at(i).toIPv4Address()){
            hostAddress = ipAddressList.at(i);
            break;
        }
    }
    if(hostAddress.toString().isEmpty())
        hostAddress = QHostAddress(QHostAddress::LocalHost);

    m_tcpServer = new QTcpServer(this);
    if(!m_tcpServer->listen(hostAddress, 25000)){
        QMessageBox::critical(this, "TCP Server",
                              QString("서버를 시작할 수 없음. 에러메세지 : %1").arg(m_tcpServer->errorString()));
        close();
        return;
    }
    ui->labelStatus->setText(QString("서버 동작 중 \n\n IP : %1 \n\n PORT : %2")
                                 .arg(hostAddress.toString()).arg(m_tcpServer->serverPort()));
    connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(slot_newConnection()));
    ui->textEdit->clear();
}

void Widget::slot_newConnection()
{
    QTcpSocket *clientConnection = m_tcpServer->nextPendingConnection(); // 새로 접속한 클라이언트의 디스크립션을 저장
    connect(clientConnection, SIGNAL(disconnected()), clientConnection, SLOT(deleteLater()));// disconnection 되면 clientConnection 오브젝트를 메모리에서 삭제

    QString currTime = QTime::currentTime().toString("hh시 mm분 ss초");
    QString text = QString("클라이언트 접속시간 : %1").arg(currTime);
    ui->textEdit->append(text);

    QByteArray message = QByteArray("Hello Client!");
    clientConnection->write(message);
    clientConnection->disconnectFromHost();
}


Widget::~Widget()
{
    delete ui;
}

























