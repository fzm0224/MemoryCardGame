#ifndef PREMIUM_H
#define PREMIUM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "gameover.h"

#define NUM_PRE 20

class Premium : public QWidget
{
    Q_OBJECT
public:
    explicit Premium(QWidget *parent = 0);
    ~Premium();
    void paintEvent(QPaintEvent *);

private:
    QPushButton *button[NUM_PRE];
    QLabel title;
    GameOver *over;
    QPushButton *b_restart;
    QPushButton *b_gotoui;

private:
    static int array[NUM_PRE];
    int clicknum;    //第几次翻转卡片

    //标志array的第i个数是否已使用，并且控制卡牌的反转
    int flag[NUM_PRE];
    int map[NUM_PRE];

    int timeid_1;

    int clickCard[2];   //保存第i次和i+1次所翻转卡片的map值

    int sec;    //定时器秒数计数

protected:
    void timerEvent(QTimerEvent *);

public:
    void startTimer_pre();
    void restart_func();

signals:
    void mysignal_pre();

public slots:
};

#endif // PREMIUM_H
