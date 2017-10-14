#include "countdowntimer.h"
#include <QPaintEngine>
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QTimer>

CountdownTimer::CountdownTimer(QWidget *parent) : QLabel(parent), timer(this){
    this->hide();

    connect(&timer, &QTimer::timeout, this, &CountdownTimer::updateProgress);
    start_time = 10;
    progress = 1;
}

void CountdownTimer::setProgress(int progress){
    this->progress = progress / 1000.00;
    this->update();
}

void CountdownTimer::updateProgress(){
    if(progress <= .0001){ //should be 0, but use .1 to account for rounding.
        timer.stop();

        this->reset();
        emit timeout();
    }
    else{
        progress -= (1.0 / (10 * start_time));
        this->update();
    }
}

void CountdownTimer::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    QPen pen;

    pen.setWidth(8);
    pen.setColor(QColor(104,255,62));

    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing);

    QRectF rect(10.0,20.0,118.0,118.0);

    int startAngle = -90 * 16;
    int spanAngle = this->progress * 360 * 16;

    painter.drawArc(rect, startAngle, spanAngle);
}

void CountdownTimer::start(){
    reset();

    timer.start(100);
    timer.blockSignals(false);
}

void CountdownTimer::reset(){
    progress = 1;
    timer.blockSignals(true);
}

