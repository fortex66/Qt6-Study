#include "widget.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    if(translator.load(":/Translator/korean.qm"))
    {
        QApplication::installTranslator(&translator);
    }
    Widget w;
    w.show();
    return a.exec();
}
