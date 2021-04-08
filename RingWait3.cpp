#include "RingWait3.h"

RingWait3::RingWait3(QWidget *parent)
    : QDialog(parent)
{
    offset=0;
    //启动定时器
    startTimer(50);
    setFixedSize(150,150);
    //去掉标题栏 设置置顶 去掉任务栏图标
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowCloseButtonHint|Qt::WindowStaysOnTopHint);

    //设置窗口背景透明
    setAttribute(Qt::WA_TranslucentBackground, true);
}

RingWait3::~RingWait3()
{}

void RingWait3::timerEvent(QTimerEvent*)
{
    ++offset;
    if(offset>11)
        offset=0;
    update();
}

void RingWait3::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    //启动反锯齿
    painter.setRenderHint(QPainter::Antialiasing, true);
    int width=this->width();
    int height=this->height();
    //画笔移动到中间
    painter.translate(width >> 1, height>> 1);

    int offsetDest=(width-30)/2;
    painter.setPen(Qt::NoPen);
    //计算小圆坐标
    for(int i=0;i<3;++i){
        QPoint point(0,0);
        painter.setBrush(QColor(50+i*50,20+i*90,40+i*5,80+i*80));
        point.setX(offsetDest*qSin((-offset+i)*M_PI/6));
        point.setY(offsetDest*qCos((-offset+i)*M_PI/6));
        painter.drawEllipse(point.x()-10, point.y()-10, 20, 20);
    }
    for(int i=0;i<9;++i){
        QPoint point(0,0);
        painter.setBrush(QColor(255,190-i*20,i*15,255-i*32));
        point.setX(offsetDest*qSin((-offset+i+3)*M_PI/6));
        point.setY(offsetDest*qCos((-offset+i+3)*M_PI/6));
        painter.drawEllipse(point.x()-10, point.y()-10, 20, 20);
    }
}
