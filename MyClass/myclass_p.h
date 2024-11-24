#ifndef MYCLASS_P_H
#define MYCLASS_P_H

#include "myclass.h"

class MyClassPrivate
{
public:
    Q_DECLARE_PUBLIC(MyClass)

    MyClassPrivate(MyClass *q);
    ~MyClassPrivate();

    void setValue(int val);
    void printValue();

private:
    int m_value;
    MyClass *q_ptr;
};

#endif // MYCLASS_P_H
