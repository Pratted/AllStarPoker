#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QPainter>

class CountdownTimer : public QLabel
{
    Q_OBJECT
public:
    CountdownTimer(QWidget *parent = Q_NULLPTR);

public slots:
    void setProgress(int progress);

protected:
    void paintEvent(QPaintEvent* event);
private:
    double progress;
    QPen pen;
    QPainter painter;
};

#endif // COUNTDOWNTIMER_H
