#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QMutex>

class MyThread : public QThread
{
    Q_OBJECT // signal slot사용을 위해 추가

public:
    MyThread(int num);

private:
    bool    m_threadStop;
    int     m_number;
    QMutex  m_mutex;

public:
    void stop();

signals:
    void sig_threadMsg(const QString &);

protected:
    virtual void run();

};

#endif // MYTHREAD_H
