#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(click_btn()));

}

void Widget::click_btn()
{
    QString str = QString("안녕하세요");
    ui->label->setText(str);
}

Widget::~Widget()
{
    delete ui;
}
