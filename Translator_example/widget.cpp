#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pbtBtn2->setText(tr("Hello"));
}

Widget::~Widget()
{
    delete ui;
}
