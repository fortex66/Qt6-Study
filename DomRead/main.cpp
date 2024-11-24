#include <QCoreApplication>
#include <QtXml>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDomDocument document;
    QFile file(":/resources/dom.xml");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file.";
        return -1;
    }

    if(!document.setContent(&file))
    {
        qDebug() << "Failed to open file.";
        file.close();
        return -1;
    }

    QDomElement root = document.firstChildElement();
    QDomNodeList nodes = root.elementsByTagName("KR");

    qDebug() << "노드 개수 : " << nodes.count();
    for(int i = 0; i < nodes.count(); i++)
    {
        QDomNode elm = nodes.at(i);
        if(elm.isElement())
        {
            QDomElement e = elm.toElement();
            qDebug() << "Name : " << e.attribute("Name");
        }
    }


    return a.exec();
}
