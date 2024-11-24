#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    // 640 x 480 x 4
    QImage m_sourceImg;
    QImage m_targetImg;
    QImage m_resultImg;

    int m_imgWidth;  // 이미지 가로크기
    int m_imgHeight; // 이미지 세로크기
    int m_imgSize;   // 이미지 가로크기 X 이미지 세로크기 X 4

    // 한 픽셀씩 검색을 할 수 있는데 속도가 너무 느리므로
    // 배열 변수로 포인터 주소를 찾아가는 방법 사용
    void chromakeyProcess(QImage& sourceImage, QImage& targetImage, QImage& resultImage);

private slots:
    void slotChromakey();

};
#endif // WIDGET_H
