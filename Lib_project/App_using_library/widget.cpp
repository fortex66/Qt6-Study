#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_myUtil = new MyUtil();

    connect(ui->pbtResult, SIGNAL(pressed()), this, SLOT(slot_pbtResult()));

}

void Widget::slot_pbtResult()
{
    qint32 Avalue = ui->leAvalue->text().toInt();
    qint32 Bvalue = ui->leBvalue->text().toInt();

    qint32 result = m_myUtil->getSumValue(Avalue, Bvalue);
    QString resStr = QString("%1").arg(result);
    ui->leResult->setText(resStr);
}

Widget::~Widget()
{
    delete ui;
}
