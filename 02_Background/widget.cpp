#include "widget.h"
#include <QPainter>
#include <QPaintEvent>
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(nullptr, Qt::FramelessWindowHint)
{
    Q_UNUSED(parent)

    m_device = QPixmap(":/Images/background.png");
    QBitmap bitmap = m_device.createHeuristicMask();
    setFixedSize(m_device.size());
    setMask(bitmap);

    m_pbtButton = new QPushButton("안녕하세요.", this);

    connect(m_pbtButton, SIGNAL(pressed()), this, SLOT(slot_pbtButton()));

    m_pbtButton->setGeometry(50, 100, 70, 30);
}

void Widget::slot_pbtButton()
{
    qDebug() << Q_FUNC_INFO;
}

void Widget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    painter.drawPixmap(event->rect(), m_device);

    painter.setPen(QColor(116, 116, 118));
    painter.setBrush(QColor(116, 116, 118));
    painter.drawRect(25, 65, 145, 260);
}

Widget::~Widget() {}
