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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *leKeyboard;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *leMonitor;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pbtSave;
    QPushButton *pbtRead;
    QTextEdit *textEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(600, 393);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        leKeyboard = new QLineEdit(groupBox);
        leKeyboard->setObjectName("leKeyboard");

        horizontalLayout_2->addWidget(leKeyboard);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        leMonitor = new QLineEdit(groupBox);
        leMonitor->setObjectName("leMonitor");

        horizontalLayout->addWidget(leMonitor);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pbtSave = new QPushButton(Widget);
        pbtSave->setObjectName("pbtSave");

        horizontalLayout_3->addWidget(pbtSave);

        pbtRead = new QPushButton(Widget);
        pbtRead->setObjectName("pbtRead");

        horizontalLayout_3->addWidget(pbtRead);


        verticalLayout_2->addLayout(horizontalLayout_3);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName("textEdit");

        verticalLayout_2->addWidget(textEdit);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\352\260\200\352\262\251\354\240\225\353\263\264", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\355\202\244\353\263\264\353\223\234 \352\260\200\352\262\251(\354\233\220)", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\353\252\250\353\213\210\355\204\260 \352\260\200\352\262\251(\354\233\220)", nullptr));
        pbtSave->setText(QCoreApplication::translate("Widget", "\352\260\200\352\262\251 \354\240\225\353\263\264 \354\240\200\354\236\245", nullptr));
        pbtRead->setText(QCoreApplication::translate("Widget", "\352\260\200\352\262\251 \354\240\225\353\263\264 \354\235\275\354\226\264 \354\230\244\352\270\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
