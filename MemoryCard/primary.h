#ifndef PRIMARY_H
#define PRIMARY_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "gameover.h"

#define NUM_PRI 12

class Primary : public QWidget
{
    Q_OBJECT
public:
    explicit Primary(QWidget *parent = 0);
    ~Primary();
    void paintEvent(QPaintEvent *);

private:
    QPushButton *button[NUM_PRI];

    QLabel title;

    GameOver *over;

    QPushButton *b_restart;
    QPushButton *b_gotoui;

private:
    static int array[NUM_PRI];
    int clicknum;    //第几次翻转卡片

    //标志array的第i个数是否已使用，并且控制卡牌的反转
    int flag[NUM_PRI];
    int map[NUM_PRI];

    int timeid_1;

    int clickCard[2];   //保存第i次和i+1次所翻转卡片的map值

    int sec;    //定时器秒数计数

protected:
    void timerEvent(QTimerEvent *);

public:
    void startTimer_pri();
    void restart_func();

signals:
    void mysignal_pri();

public slots:
};

#endif // PRIMARY_H
