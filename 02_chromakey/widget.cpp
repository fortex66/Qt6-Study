#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("크로마키 예제");

    connect(ui->pbtChromakey, SIGNAL(clicked(bool)), this, SLOT(slotChromakey()));

    m_sourceImg = QImage(":/images/source.png");
    m_targetImg = QImage(":/images/target.png");

    m_imgWidth = m_sourceImg.width();
    m_imgHeight = m_sourceImg.height();
    m_imgSize = m_imgWidth * m_imgHeight * 4;

    qDebug() << "format : " << m_sourceImg.format();
    m_resultImg = QImage(m_imgWidth, m_imgHeight, QImage::Format_RGB32);
}

// 복잡한 기능 구현은 slot함수에서 분리시키는게 좋다.

void Widget::chromakeyProcess(QImage& sourceImage, QImage& targetImage, QImage& resultImage)
{
    // 배열 포인터 주소를 알아야 접근할수 있으므로
    // bits() : 포인터 주소를 넘겨준다.
    uchar *pSourceData = sourceImage.bits();
    uchar *pTargetData = targetImage.bits();
    uchar *pResultData = resultImage.bits();

    QColor maskColor = QColor::fromRgb(sourceImage.pixel(1, 1));
    int kred   = maskColor.red();
    int kgreen = maskColor.green();
    int kblue  = maskColor.blue();

    int sPixRed, sPixGreen, sPixBlue;
    for(int inc = 0; inc < m_imgSize; inc += 4)
    {
        // BGR 순으로 들어가기 대문 2 1 0
        sPixRed   = pSourceData[inc+2];
        sPixGreen = pSourceData[inc+1];
        sPixBlue  = pSourceData[inc];

        if((abs(kred - sPixRed) + abs(kgreen - sPixGreen) + abs(kblue - sPixBlue)) / 5 < 22)
        {
            // 녹색
            pResultData[inc+2] = pTargetData[inc+2];
            pResultData[inc+1] = pTargetData[inc+1];
            pResultData[inc+0] = pTargetData[inc+0];
        }
        else
        {
            // 사람
            pResultData[inc+2] = pSourceData[inc+2];
            pResultData[inc+1] = pSourceData[inc+1];
            pResultData[inc+0] = pSourceData[inc+0];
        }
    }

}

void Widget::slotChromakey()
{
    chromakeyProcess(m_sourceImg, m_targetImg, m_resultImg);

    int w = ui->labelChromakey->width();
    int h = ui->labelChromakey->height();

    QPixmap drawPixmap = QPixmap::fromImage(m_resultImg).scaled(w,h);
    ui->labelChromakey->setPixmap(drawPixmap);
}

Widget::~Widget()
{
    delete ui;
}
