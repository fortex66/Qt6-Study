/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QSlider *hSlider;
    QLineEdit *leText;
    QLineEdit *leTextCopy;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(763, 253);
        hSlider = new QSlider(Widget);
        hSlider->setObjectName("hSlider");
        hSlider->setGeometry(QRect(80, 120, 160, 16));
        hSlider->setOrientation(Qt::Horizontal);
        leText = new QLineEdit(Widget);
        leText->setObjectName("leText");
        leText->setGeometry(QRect(310, 110, 113, 24));
        leTextCopy = new QLineEdit(Widget);
        leTextCopy->setObjectName("leTextCopy");
        leTextCopy->setGeometry(QRect(530, 110, 113, 24));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
