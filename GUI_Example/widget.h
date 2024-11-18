#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton *m_button; // QPushButton을 가르키는 포인터
    QString m_str;

private slots:
    void slot_btn();
};


#endif // WIDGET_H
