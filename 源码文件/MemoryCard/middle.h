#ifndef MIDDLE_H
#define MIDDLE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "gameover.h"

#define NUM_MID 20

class Middle : public QWidget
{
    Q_OBJECT
public:
    explicit Middle(QWidget *parent = 0);
    ~Middle();
    void paintEvent(QPaintEvent *);

private:
    QPushButton *button[NUM_MID];
    QLabel title;
    GameOver *over;
    QPushButton *b_restart;
    QPushButton *b_gotoui;

private:
    static int array[NUM_MID];
    int clicknum;    //第几次翻转卡片

    //标志array的第i个数是否已使用，并且控制卡牌的反转
    int flag[NUM_MID];
    int map[NUM_MID];

    int timeid_1;

    int clickCard[2];   //保存第i次和i+1次所翻转卡片的map值

    int sec;    //定时器秒数计数

protected:
    void timerEvent(QTimerEvent *);

public:
    void startTimer_mid();
    void restart_func();

signals:
    void mysignal_mid();

public slots:
};

#endif // MIDDLE_H
