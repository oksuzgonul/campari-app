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
    if (appTimer->getTimeSeconds() >= appTimer->getGoalTime()) {

        ui->sessionLabel->setText("Study finished");
        appTimer->stop();
    }
    else
    {
        ui->sessionLabel->setText("Time elapsed: " + QString::number(appTimer->getTimeSeconds()));
    }
}

void MainWindow::on_startButton_clicked()
{
    appTimer->start(1000);
}
