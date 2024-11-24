#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "myutil.h"

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

    MyUtil *m_myUtil;

private:
    Ui::Widget *ui;

private slots:
    void slot_pbtResult();
};
#endif // WIDGET_H
