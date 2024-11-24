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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leAvalue;
    QLabel *label;
    QLineEdit *leBvalue;
    QLabel *label_2;
    QLineEdit *leResult;
    QPushButton *pbtResult;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(349, 66);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        leAvalue = new QLineEdit(Widget);
        leAvalue->setObjectName("leAvalue");

        horizontalLayout->addWidget(leAvalue);

        label = new QLabel(Widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        leBvalue = new QLineEdit(Widget);
        leBvalue->setObjectName("leBvalue");

        horizontalLayout->addWidget(leBvalue);

        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        leResult = new QLineEdit(Widget);
        leResult->setObjectName("leResult");

        horizontalLayout->addWidget(leResult);


        verticalLayout->addLayout(horizontalLayout);

        pbtResult = new QPushButton(Widget);
        pbtResult->setObjectName("pbtResult");

        verticalLayout->addWidget(pbtResult);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "+", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "=", nullptr));
        pbtResult->setText(QCoreApplication::translate("Widget", "\352\263\204\354\202\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
