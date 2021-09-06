#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize the appTimer class and bind the signal timeout to the slot UpdateTime
    appTimer = new AppTimer(this);
    connect(appTimer, SIGNAL(timeout()), this, SLOT(UpdateTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTime()
{
    if (appTimer->isTimerComplete()) {
        appTimer->stop();
        switch (appTimer->getMode()) {
        case LONG_BREAK:
            appTimer->SessionReset();
        case SHORT_BREAK:
            appTimer->setMode(MAIN_TIMER);
        case MAIN_TIMER:
            if (appTimer->isCountReached())
            {
                appTimer->setMode(LONG_BREAK);
            } else
            {
                appTimer->setMode(SHORT_BREAK);
                appTimer->incrementStudyCount();
            }
        }

        appTimer->startTimer();
    }
    else
    {
        ui->sessionLabel->setText("Time elapsed: " + QString::number(appTimer->getTimeSeconds()));
    }
}

void MainWindow::on_startButton_clicked()
{
    appTimer->startTimer();
}

void MainWindow::on_pauseButton_clicked()
{
    appTimer->pause();
}


void MainWindow::on_restartButton_clicked()
{
    appTimer->restart();
}


void MainWindow::on_goalTimeSlider_valueChanged(int value)
{
    appTimer->setGoalTime(value);
}


void MainWindow::on_smallBreakSlider_valueChanged(int value)
{
    appTimer->setGoalRestSmall(value);
}


void MainWindow::on_sessionCountSlider_valueChanged(int value)
{
    appTimer->setGoalCount(value);
}


void MainWindow::on_bigBreakSlider_valueChanged(int value)
{
    appTimer->setGoalRestBig(value);
}

