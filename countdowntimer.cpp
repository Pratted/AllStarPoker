#include "countdowntimer.h"

CountdownTimer::CountdownTimer(QWidget *parent) : QLabel(parent), painter(this){
    this->hide();

    pen.setWidth(8);
    pen.setColor(QColor(104,255,62));

    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing);
}

void CountdownTimer::setProgress(int progress){
    this->progress = progress / 1000.00;
    this->update();
}

void CountdownTimer::paintEvent(QPaintEvent* event){
    QRectF rect(10.0,20.0,118.0,118.0);

    int startAngle = -90 * 16;
    int spanAngle = this->progress * 360 * 16;

    painter.drawArc(rect, startAngle, spanAngle);
}
