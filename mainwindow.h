#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "apptimer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void UpdateTime();

    void on_startButton_clicked();

    void on_pauseButton_clicked();

    void on_restartButton_clicked();

private:
    Ui::MainWindow *ui;
    //QTimer * appTimer;
    AppTimer * appTimer;
    int timeSeconds;
};
#endif // MAINWINDOW_H
