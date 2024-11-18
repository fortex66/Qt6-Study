#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

    // 사원 정보 구조체
    typedef struct _tEmployee{
        int num;
        QString name;
        QString part;
    } tEmployee;

    QList<tEmployee> m_employeeList; // 사원들의 정보를 저장할 리스트

private:
    Ui::Widget *ui;

private slots:
    void slot_pbtSave();
    void slot_pbtPrint();

};
#endif // WIDGET_H
