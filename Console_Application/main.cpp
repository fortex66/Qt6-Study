#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int myvalue = 10;

    qDebug() << "Hello world, myvalue = " << myvalue;
    qDebug("Hello world, myvalue = %d",myvalue);

    return a.exec();
}
GU
