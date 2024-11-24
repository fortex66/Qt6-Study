#include "ImageButton.h"
#include <QPainter>

#define BEHAVIOUR_NOMAL     0
#define BEHAVIOUR_ENTER     1
#define BEHAVIOUR_LEAVE     2
#define BEHAVIOUR_PRESS     3
#define BEHAVIOUR_DISABLE   4

ImageButton::ImageButton(QWidget *parent)
    : QWidget{parent}, m_disabled(false)
{
    m_behavior = BEHAVIOUR_NOMAL;
    QImage image(":/Images/normal.png");

    setFixedSize(QSize(image.width(), image.height()));
}

void ImageButton::setDisabled(bool val)
{
    m_disabled = val;
    update(); // paintEvent 호출(무조건 다시 그려야하는 경우 repaint() 사용

}

void ImageButton::paintEvent(QPaintEvent* event)
{
    QPainter painter;
    painter.begin(this);

    if(m_disabled == true){
        m_imgFileName = QString(":/Images/disable.png");
    } else {
        if(m_behavior == BEHAVIOUR_NOMAL)
            m_imgFileName = QString(":/Images/normal.png");
        else if(m_behavior == BEHAVIOUR_ENTER)
            m_imgFileName = QString(":/Images/enter.png");
        else if(m_behavior == BEHAVIOUR_LEAVE)
            m_imgFileName = QString(":/Images/normal.png");
        else if(m_behavior == BEHAVIOUR_PRESS)
            m_imgFileName = QString(":/Images/press.png");
    }

    QImage image(m_imgFileName);

    painter.drawImage(0,0,image);

    painter.end();
}

void ImageButton::enterEvent(QEnterEvent* event)
{
    m_behavior = BEHAVIOUR_ENTER;
    update();
    emit hovering();
}

void ImageButton::leaveEvent(QEvent* event)
{
    m_behavior = BEHAVIOUR_NOMAL;
    update();
}

void ImageButton::mousePressEvent(QMouseEvent* event)
{
    m_behavior = BEHAVIOUR_PRESS;
    update();

    emit clicked();
}

void ImageButton::mouseReleaseEvent(QMouseEvent* event)
{
    m_behavior = BEHAVIOUR_ENTER;
    update();
}



void ImageButton::mouseDoubleClickEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
}
