#include "myclass_p.h"
#include <QDebug>

MyClassPrivate::MyClassPrivate(MyClass *q)
{
    q_ptr = q;
}

MyClassPrivate::~MyClassPrivate()
{

}

void MyClassPrivate::setValue(int val)
{
    m_value = val;
}

void MyClassPrivate::printValue()
{
    Q_Q(MyClass);

    qDebug() << "MyClass의 m_value : " << q->getValue();
    qDebug() << "MyClass의 m_value : " << m_value;
}
