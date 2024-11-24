#include "MyThread.h"

MyThread::MyThread(int num)
{
    m_number = num;
}

void MyThread::stop()
{
    m_threadStop = true;

    QString str = QString("[Thread 번호: %1] MyThread 중지").arg(m_number);
    emit sig_threadMsg(str);
}

void MyThread::run()
{
    m_threadStop = false;
    int i = 0;

    while(!m_threadStop)
    {
        m_mutex.lock();

        QString str = QString("[Thread 번호 : %1] MyThread %2 동작").arg(m_number).arg(i);
        i++;

        emit sig_threadMsg(str);

        m_mutex.unlock();

        sleep(1);
    }
}
