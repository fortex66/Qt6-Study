#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(300,200);

    m_str = QString("버튼");
    m_button = new QPushButton(m_str, this); // 힙 메모리에 QPushButton객체를 생성하고 그 주소를 m_button에 저장
    m_button->setGeometry(10, 20, 100, 100); // m_button이 가르키는 힙 메모리의 QPushButton 객체의 맴버 함수에 접근하므로 -> 사용

    connect(m_button, SIGNAL(pressed()), this, SLOT(slot_btn()));

}

void Widget::slot_btn(){
    qDebug() << "Button Click!";
}

Widget::~Widget() {}
