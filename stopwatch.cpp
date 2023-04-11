#include "stopwatch.h"
#include <QDebug>

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
    , timer(new QTimer())
    , ctime(0)
    , roundtime(0)
    , round(1)
{
    connect(timer, &QTimer::timeout, this, &Stopwatch::on_update);
}

void Stopwatch::start()
{
    timer->start(100);
}

void Stopwatch::stop()
{
    timer->stop();
}

void Stopwatch::clear()
{
    ctime = 0;
    roundtime = 0;
    round = 1;
    emit ctime_changed(ctime);
}

void Stopwatch::on_update()
{
    ctime += 0.1;
    roundtime += 0.1;
    emit ctime_changed(ctime);
    qDebug() << ctime;
}

void Stopwatch::next_round()
{
    round += 1;
    roundtime = 0;
}

float Stopwatch::getTime()
{
    return ctime;
}

float Stopwatch::getRoundTime()
{
    return roundtime;
}

int Stopwatch::getRound()
{
    return round;
}
