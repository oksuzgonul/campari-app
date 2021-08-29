#ifndef APPTIMER_H
#define APPTIMER_H

#include <QTimer>
#include <QElapsedTimer>

class AppTimer : public QTimer
{
private:
    typedef QTimer inherited;

    // current time counter, will be decremented every second by the timer
    QElapsedTimer elapsed;

    // the time set by user for the counter - miliseconds
    int goalTime;

    // number of times the user reached goalTime
    int studyCount;

    // goal set by user for studyCount
    int goalCount;

    // small rest time between goalTime study blocks - miliseconds
    int goalRestSmall;

    // big rest time after goalCount is reached - miliseconds
    int goalRestBig;

public:
    explicit AppTimer(QObject *parent = nullptr);

    // start the timer
    void startTimer();

    // getter for the time elapsed
    int getTimeSeconds();

    // setter and getter for goalTime
    void setGoalTime(int time);
    int getGoalTime();

    // increment studyCount;
    void incrementStudyCount();
    int getStudyCount();

    // setter and getter for goalCount
    void setGoalCount(int count);
    int getGoalCount();

    // setter and getter for goalRestSmall
    void setGoalRestSmall(int time);
    int getGoalRestSmall();

    // setter and getter for goalRestSmall
    void setGoalRestBig(int time);
    int getGoalRestBig();

    // pause the timer
    void pause();

    // restart the timer
    void restart();
};

#endif // APPTIMER_H
