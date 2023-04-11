#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject
{
    QTimer* timer;
    float ctime;
    int round;
    float roundtime;
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);
    float getTime();
    float getRoundTime();
    int getRound();
    void start();
    void stop();
    void clear();
    void next_round();

signals:
    void ctime_changed(float value);

public slots:
    void on_update();

};

#endif // STOPWATCH_H
