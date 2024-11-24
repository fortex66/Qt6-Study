#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./mydb.db");

    if(!db.open()){
        qDebug() << db.lastError();
    }

    QSqlQuery qry;
    qry.prepare("CREATE TABLE IF NOT EXISTS student"
                "(id INTEGER UNIQUE PRIMARY KEY, department VARCHAR(30), name VARCHAR(30))");
    if(!qry.exec())
        qDebug() << qry.lastError();

    qry.prepare("INSERT INTO student (id, department, name) VALUES (1, '국어국문학과', '홍길동')");
    if(!qry.exec())
        qDebug() << qry.lastError();

    qry.prepare("INSERT INTO student (id, department, name) VALUES (2, '컴퓨터공학과', '김아라')");
    if(!qry.exec())
        qDebug() << qry.lastError();

    qry.prepare("INSERT INTO student (id, department, name) VALUES (3, '심리학과', '김인수')");
    if(!qry.exec())
        qDebug() << qry.lastError();

    qry.prepare("INSERT INTO student (id, department, name) VALUES (4, '법학과', '김은경')");
    if(!qry.exec())
        qDebug() << qry.lastError();

    QSqlTableModel *model = new QSqlTableModel(this, db);

    model->setTable("student");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "학과");
    model->setHeaderData(2, Qt::Horizontal, "성명");

    ui->tableView->setModel(model);

    connect(ui->pbtQuery, SIGNAL(pressed()), this, SLOT(slot_pbtQuery()));
}

void Widget::slot_pbtQuery()
{
    ui->textEdit->clear();

    QSqlQuery qry;
    qry.prepare("SELECT department, name From student");
    if(!qry.exec())
        qDebug() << qry.lastError();
    else
    {
        QSqlRecord rec = qry.record();
        int cols = rec.count();

        QString colStr;
        for(int c = 0; c < cols; c++)
        {
            colStr = QString("[컬럼 : %1]  %2").arg(c).arg(rec.fieldName(c));
            ui->textEdit->append(colStr);
        }

        QString rowStr;
        for(int r = 0; qry.next(); r++)
        {
            for(int c = 0; c < cols; c++)
            {
                rowStr = QString("[행 : %1]  %2  %3").arg(r).arg(rec.fieldName(c)).arg(qry.value(c).toString());
                ui->textEdit->append(rowStr);
            }
        }
    }
}

Widget::~Widget()
{
    delete ui;
}
