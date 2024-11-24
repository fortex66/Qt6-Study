#include <QCoreApplication>
#include <QThread>
#include <QDebug>

#include <QWaitCondition>
#include <QMutex>

int num;

QMutex mutex;
QWaitCondition incNumber;

class Producer : public QThread
{
public:
    Producer() {}

protected:
    virtual void run()
    {
        for(int i = 0; i < 10; i++)
        {
            sleep(1);

            mutex.lock();
            ++num;
            incNumber.wakeAll();
            mutex.unlock();
        }
    }
};

class Consumer : public QThread
{
public:
    Consumer() {}

protected:
    virtual void run()
    {
        for(int i = 0; i < 10; i++)
        {
            mutex.lock();
            incNumber.wait(&mutex);
            mutex.unlock();

            qDebug("num : %d", num);
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer producer;
    Consumer consumer;

    producer.start();
    consumer.start();


    return a.exec();
}
