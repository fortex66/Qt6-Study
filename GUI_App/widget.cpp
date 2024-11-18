#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this); // setupUI()는 Qt Designer에서 정의한 모든 위젯을 생성하고 부모 위젯에 추가한다.

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slot_pushbutton()));
    // ui는 ui::Widget 클래스의 포인터 이므로 Designer를 사용하여 UI를 설계하면, ui_widget.h파일이 자동으로 생성되며, 여기에 UI 구성요소가 정의된다.
    // ui 객체는 ui_widget.h에서 생성된 클래스의 인스턴스로 모든 UI 위젯(버튼,라벨 등)의 멤버 변수를 관리한다.
    // UI 위젯에 접근하려면 ui->pushButton처럼 ui 객체를 통해 접근해야 한다.
}

void Widget::slot_pushbutton(){
    qDebug() << Q_FUNC_INFO <<  "Hello world";
}

Widget::~Widget()
{
    delete ui;
}
