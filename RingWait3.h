#ifndef RINGWAIT3_H
#define RINGWAIT3_H

#include <QtMath>
#include <QDialog>
#include <QPainter>
#include <QTimerEvent>
#include <QPainterPath>

class RingWait3 : public QDialog
{
    Q_OBJECT

private:
    int offset;

public:
    RingWait3(QWidget *parent = nullptr);
    ~RingWait3();

protected:
    void paintEvent(QPaintEvent*);
    void timerEvent(QTimerEvent*);
};
#endif
