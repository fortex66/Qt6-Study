#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QWidget>

class ImageButton : public QWidget
{
    Q_OBJECT
public:
    explicit ImageButton(QWidget *parent = nullptr);
    void setDisabled(bool val);

private:
    QString m_imgFileName;
    qint32  m_behavior;
    bool    m_disabled;

signals:
    void hovering();
    void clicked();

protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void enterEvent(QEnterEvent* event);
    virtual void leaveEvent(QEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseDoubleClickEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);

};

#endif // IMAGEBUTTON_H
