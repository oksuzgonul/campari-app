#include "apptimer.h"

AppTimer::AppTimer(QObject *parent) : QTimer(parent)
{
   elapsed.invalidate();
   goalTime = 10;
}

void AppTimer::startTimer()
{
    elapsed.start();
    start(1000);
}

int AppTimer::getTimeSeconds()
{
    return elapsed.elapsed() / 1000;
}

void AppTimer::setGoalTime(int time)
{
    goalTime = time;
}

int AppTimer::getGoalTime()
{
    return goalTime;
}

void AppTimer::incrementStudyCount()
{
    studyCount++;
}

int AppTimer::getStudyCount()
{
    return studyCount;
}

void AppTimer::setGoalCount(int count)
{
    goalCount = count;
}

int AppTimer::getGoalCount()
{
    return goalCount;
}

void AppTimer::setGoalRestSmall(int time)
{
    goalRestSmall = time;
}

int AppTimer::getGoalRestSmall()
{
    return goalRestSmall;
}

void AppTimer::setGoalRestBig(int time)
{
    goalRestBig = time;
}

int AppTimer::getGoalRestBig()
{
    return goalRestBig;
}

void AppTimer::pause()
{
    elapsed.invalidate();
    stop();
}

void AppTimer::restart()
{
    elapsed.restart();
}
