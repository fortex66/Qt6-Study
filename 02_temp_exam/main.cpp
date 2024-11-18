#include <QCoreApplication>

#include <QTemporaryDir>
#include <QTemporaryFile>
#include <QDebug>

void createTempFile()
{
    QString fileName;

    fileName = QDir::tempPath() + "/" + "MY_TMEP.txt";

    qDebug() << "임시파일 경로 및 파일 명 : " << fileName;

    QTemporaryFile tempFile(fileName);
    tempFile.setAutoRemove(false);

    tempFile.open();

    tempFile.write("Hello World");
    tempFile.flush();

    tempFile.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    createTempFile();

    return a.exec();
}
