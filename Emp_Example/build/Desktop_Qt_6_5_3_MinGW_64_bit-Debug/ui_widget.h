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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leNum;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *leName;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lePart;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pbtSave;
    QPushButton *pbtPrint;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *textEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(398, 420);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(100, 0));
        label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(label);

        leNum = new QLineEdit(Widget);
        leNum->setObjectName("leNum");

        horizontalLayout->addWidget(leNum);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(label_2);

        leName = new QLineEdit(Widget);
        leName->setObjectName("leName");

        horizontalLayout_2->addWidget(leName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(label_3);

        lePart = new QLineEdit(Widget);
        lePart->setObjectName("lePart");

        horizontalLayout_5->addWidget(lePart);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pbtSave = new QPushButton(Widget);
        pbtSave->setObjectName("pbtSave");

        horizontalLayout_3->addWidget(pbtSave);

        pbtPrint = new QPushButton(Widget);
        pbtPrint->setObjectName("pbtPrint");

        horizontalLayout_3->addWidget(pbtPrint);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName("textEdit");

        horizontalLayout_4->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\354\202\254\354\233\220\353\262\210\355\230\270", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\354\204\261\353\252\205", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\353\266\200\354\204\234", nullptr));
        pbtSave->setText(QCoreApplication::translate("Widget", "\354\240\200\354\236\245", nullptr));
        pbtPrint->setText(QCoreApplication::translate("Widget", "\354\266\234\353\240\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
