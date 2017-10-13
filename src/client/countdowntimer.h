#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QPainter>
#include <QTimer>

class CountdownTimer : public QLabel
{
    Q_OBJECT
public:
    CountdownTimer(QWidget *parent = Q_NULLPTR);

public slots:
    void setProgress(int progress);
    void updateProgress();
    void start();

signals:
    void timeout();
protected:
    void paintEvent(QPaintEvent* event);
private:
    double progress;
    int start_time;
    QTimer timer;
};

#endif // COUNTDOWNTIMER_H
