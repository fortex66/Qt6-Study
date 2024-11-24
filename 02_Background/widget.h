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

    QPixmap m_device;
    QPushButton *m_pbtButton;

private slots:
    void slot_pbtButton();

protected:
    virtual void paintEvent(QPaintEvent* event);
};
#endif // WIDGET_H
