#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "MyThread.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    MyThread *m_thread1; // 1번 Thread 오브젝트 생성
    MyThread *m_thread2; // 2번 Thread 오브젝트 생성

private slots:
    void slot_pbtStart();
    void slot_pbtStop();
    void slot_pbtIsRunning();

    void slot_threadMsg(const QString &);

    void slot_started();
    void slot_finished();
};
#endif // WIDGET_H
