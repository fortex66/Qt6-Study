#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pbtStart, SIGNAL(pressed()), this, SLOT(slot_pbtStart()));
    connect(ui->pbtStop, SIGNAL(pressed()), this, SLOT(slot_pbtStop()));
    connect(ui->pbtIsRunning, SIGNAL(pressed()), this, SLOT(slot_pbtIsRunning()));

    m_thread1 = new MyThread(1); // 메모리 할당
    m_thread2 = new MyThread(2);

    connect(m_thread1, SIGNAL(sig_threadMsg(const QString &)), this, SLOT(slot_threadMsg(const QString &)));
    connect(m_thread2, SIGNAL(sig_threadMsg(const QString &)), this, SLOT(slot_threadMsg(const QString &)));

    connect(m_thread1, SIGNAL(started()), this, SLOT(slot_started()));
    connect(m_thread1, SIGNAL(finished()), this, SLOT(slot_finished()));

}

void Widget::slot_pbtStart()
{
    ui->textEdit->clear();

    m_thread1->start();
    m_thread2->start();
}

void Widget::slot_pbtStop()
{
    m_thread1->stop();
    m_thread2->stop();
}

void Widget::slot_pbtIsRunning()
{
    if(m_thread1->isRunning())
        ui->textEdit->append("첫 번째 Thread 상태 : 동작중");
    else
        ui->textEdit->append("첫 번째 Thread 상태 : 중지됨");

    if(m_thread2->isRunning())
        ui->textEdit->append("두 번째 Thread 상태 : 동작중");
    else
        ui->textEdit->append("두 번째 Thread 상태 : 중지됨");
}

void Widget::slot_threadMsg(const QString &msg)
{
    ui->textEdit->append(msg);
}

void Widget::slot_started()
{
    ui->textEdit->append("첫 번째 Thread가 시작됨");
}

void Widget::slot_finished()
{
    ui->textEdit->append("첫 번째 Thread가 종료됨");
}

Widget::~Widget()
{
    delete ui;
}
