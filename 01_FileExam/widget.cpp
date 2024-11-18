#include "widget.h"
#include "ui_widget.h"

#include <QDataStream>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("QFile을 이용한 예제");

    connect(ui->pbtSave, SIGNAL(pressed()), this, SLOT(slot_pbtFileSave()));
    connect(ui->pbtRead, SIGNAL(pressed()), this, SLOT(slot_pbtFileRead()));

    m_file = new QFile();
}

void Widget::slot_pbtFileSave()
{
    QString fileName;
    fileName = QString("price.data");

    m_file->setFileName(fileName);
    if(!m_file->open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qDebug() << "File open fail";
        return;
    }

    qint32 keyboardPrice = ui->leKeyboard->text().toInt();
    qint32 monitorPrice = ui->leMonitor->text().toInt();

    QDataStream out(m_file);
    out << keyboardPrice;
    out << monitorPrice;

    m_file->close();

}

void Widget::slot_pbtFileRead()
{
    if (m_file->isOpen()) {
        m_file->close();
    }

    if (!m_file->open(QIODevice::ReadOnly)) {
        qDebug() << "File open fail.";
        return;
    }

    qint32 keyboardPrice;
    qint32 monitorPrice;

    QDataStream in(m_file);
    in >> keyboardPrice;
    in >> monitorPrice;

    m_file->close();

    QString str1 = QString("키보드 가격 : %L1").arg(keyboardPrice);
    QString str2 = QString("모니터 가격 : %L1").arg(monitorPrice);

    ui->textEdit->clear();
    ui->textEdit->append(str1);
    ui->textEdit->append(str2);
}

Widget::~Widget()
{
    delete ui;
}
