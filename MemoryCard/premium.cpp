#include "premium.h"
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QMessageBox>

int Premium::array[NUM_PRE] = {
    1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10
};

Premium::Premium(QWidget *parent) : QWidget(parent)
{
    //初始化翻转卡牌的次数
    clicknum = 0;

    //倒计时提示标签
    title.setParent(this);
    title.move(210, 20);
    title.resize(180, 50);
    //这种设计字体的方式貌似只对Label有效果，Button无效
    title.setText(QString("<center><h1>倒计时：5</h1></center>"));
    title.setStyleSheet("QLabel{"
                        "border-image:url(:/new/prefix1/res/title.jpg)"
                        "}");

    for (int i = 0; i < 2; i++)
    {
        clickCard[i] = 0;
    }

    //设置随机数种子
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    for (int i = 0; i < 20; i++)
    {
        flag[i] = 0;
        map[i] = 0;

        button[i] = new QPushButton(this);
        button[i]->resize(80, 120);
    }

    button[0]->move(40, 90);
    button[1]->move(150, 90);
    button[2]->move(260, 90);
    button[3]->move(370, 90);
    button[4]->move(480, 90);
    button[5]->move(40,  226);
    button[6]->move(150, 226);
    button[7]->move(260, 226);
    button[8]->move(370, 226);
    button[9]->move(480, 226);
    button[10]->move(40, 362);
    button[11]->move(150, 362);
    button[12]->move(260, 362);
    button[13]->move(370, 362);
    button[14]->move(480, 362);
    button[15]->move(40,  498);
    button[16]->move(150, 498);
    button[17]->move(260, 498);
    button[18]->move(370, 498);
    button[19]->move(480, 498);

    b_restart = new QPushButton(this);
    b_restart->move(35, 630);
    b_restart->resize(100, 40);
    b_restart->setText("重新开始");
    b_restart->setStyleSheet("QPushButton{"
                             "border-image:url(:/new/prefix1/res/a1.png)"
                             "}"

                             "QPushButton:pressed{"
                             "border-image:url(:/new/prefix1/res/a2.png)"
                             "}");

    b_gotoui = new QPushButton(this);
    b_gotoui->move(465, 630);
    b_gotoui->resize(100, 40);
    b_gotoui->setText("回主界面");
    b_gotoui->setStyleSheet("QPushButton{"
                            "border-image:url(:/new/prefix1/res/a1.png)"
                            "}"

                            "QPushButton:pressed{"
                            "border-image:url(:/new/prefix1/res/a2.png)"
                            "}");

    //屏蔽按钮的信号
    for (int i = 0; i < 20; i++)
    {
        button[i]->blockSignals(true);
    }
    b_restart->blockSignals(true);
    b_gotoui->blockSignals(true);

    for (int i = 0; i < 20; i++)
    {
        connect(button[i], &QPushButton::clicked, this,
                [=]()
                {
                    flag[i] = 1;
                    update();

                    clicknum++;

                    clickCard[clicknum % 2] = map[i];

                    if (clicknum % 2 == 0)
                    {
                        if (clickCard[1] != clickCard[0])
                        {
                            //翻转所有卡片
                            for (int i = 0; i < 20; i++)
                            {
                                flag[i] = 1;
                            }
//                            QMessageBox::warning(this, "游戏结束", "高级难度挑战失败，你记错位置了，游戏结束!");
                            over = new GameOver(false, 3);
                        }
                    }

                    if (clicknum == 20)
                    {
//                        QMessageBox::about(this, "游戏结束", "高级难度挑战成功，你真厉害，记忆大师！");
                        over = new GameOver(true, 3);
                    }
                }
                );
    }

    //重新开始按钮信号处理
    connect(b_restart, &QPushButton::pressed, this,
            [=]()
            {
                this->restart_func();
                this->startTimer_pre();
            }
            );

    //回主界面按钮信号处理
    connect(b_gotoui, &QPushButton::pressed, this,
            [=]()
            {
                emit mysignal_pre();
            }
            );
}

Premium::~Premium()
{

}

void Premium::paintEvent(QPaintEvent *)
{
    QPainter p(this);   //创建画家，指定窗口为绘图设备

    //背景图
    p.drawPixmap(rect(), QPixmap(":/new/prefix1/res/background.jpg"));

    for (int i = 0; i < 20; i++)
    {
        if (map[i] == 0 || flag[i] == 0)
        {
            button[i]->setStyleSheet("QPushButton{"
                                    "border-image:url(:/new/prefix1/res/card1.jpg)"
                                    "}");
        }
        else if (map[i] == 1)
        {
            button[i]->setStyleSheet("QPushButton{"
                                    "border-image:url(:/new/prefix1/res/star0.jpg)"
                                    "}");
//            button[i]->setStyleSheet("QPushButton{"
//                                    "background-color:red"
//                                    "}");
        }
        else if (map[i] == 2)
        {
            button[i]->setStyleSheet("QPushButton{"
                                    "border-image:url(:/new/prefix1/res/star1.jpg)"
                                    "}");
//            button[i]->setStyleSheet("QPushButton{"
//                                    "background-color:green"
//                                    "}");
        }
        else if (map[i] == 3)
        {
            button[i]->setStyleSheet("QPushButton{"
                                    "border-image:url(:/new/prefix1/res/star2.jpg)"
                                    "}");
//            button[i]->setStyleSheet("QPushButton{"
//                                    "background-color:white"
//                                    "}");
        }
        else if (map[i] == 4)
        {
            button[i]->setStyleSheet("QPushButton{"
                                    "border-image:url(:/new/prefix1/res/star3.jpg)"
                                    "}");
//            button[i]->setStyleSheet("QPushButton{"
//                                    "background-color:black"
//                                    "}");
        }
        else if (map[i] == 5)
        {
            button[i]->setStyleSheet("QPushButton{"
                                    "border-image:url(:/new/prefix1/res/star4.jpg)"
                                    "}");
//            button[i]->setStyleSheet("QPushButton{"
//                                    "background-color:yellow"
//                                    "}");
        }
        else if (map[i] == 6)
        {
            button[i]->setStyleSheet("QPushButton{"
                                    "border-image:url(:/new/prefix1/res/star5.jpg)"
                                    "}");
//            button[i]->setStyleSheet("QPushButton{"
//                                    "background-color:gray"
//                                    "}");
        }
        else if (map[i] == 7)
        {
            button[i]->setStyleSheet("QPushButton{"
                                    "border-image:url(:/new/prefix1/res/star6.jpg)"
                                    "}");
//            button[i]->setStyleSheet("QPushButton{"
//                                    "background-color:pink"
//                                    "}");
        }
        else if (map[i] == 8)
        {
            button[i]->setStyleSheet("QPushButton{"
                                    "border-image:url(:/new/prefix1/res/star7.jpg)"
                                    "}");
//            button[i]->setStyleSheet("QPushButton{"
//                                    "background-color:blue"
//                                    "}");
        }
        else if (map[i] == 9)
        {
            button[i]->setStyleSheet("QPushButton{"
                                    "border-image:url(:/new/prefix1/res/star8.jpg)"
                                    "}");
//            button[i]->setStyleSheet("QPushButton{"
//                                    "background-color:brown"
//                                    "}");
        }
        else if (map[i] == 10)
        {
            button[i]->setStyleSheet("QPushButton{"
                                    "border-image:url(:/new/prefix1/res/star9.jpg)"
                                    "}");
//            button[i]->setStyleSheet("QPushButton{"
//                                    "background-color:purple"
//                                    "}");
        }
    }
}

void Premium::timerEvent(QTimerEvent *)
{
    int tmp;

    sec++;

    if (5 - sec > 0)
    {
        title.setText(QString("<center><h1>倒计时：%1</h1></center>").arg(5 - sec));
    }

    if (sec == 5)
    {
        for (int i = 0; i < 20; i++)
        {
            while (1)
            {
                tmp = qrand() % 20;

                if(flag[tmp] == 0)
                {
                    map[i] = array[tmp];
                    flag[tmp] = 1;
                    break;
                }
            }
//            qDebug() << map[i];
        }

        title.setText("<center><h1>18秒的记忆</h1></center>");
        update();
    }
    else if (sec == 23)
    {
        title.setText("<center><h1>开始翻牌</h1></center>");
        for (int i = 0; i < 20; i++)
        {
            //使卡牌反转过去
            flag[i] = 0;
        }
        update();

        //解除按钮信号屏蔽
        for (int i = 0; i < 20; i++)
        {
            button[i]->blockSignals(false);
        }
        b_restart->blockSignals(false);
        b_gotoui->blockSignals(false);

        killTimer(timeid_1);
    }
}

void Premium::startTimer_pre()
{
    //初始化定时器秒数为0
    sec = 0;

    //定时器
    timeid_1 = this->startTimer(1000);
    update();
}

void Premium::restart_func()
{
    title.setText(QString("<center><h1>倒计时：5</h1></center>"));
    clicknum = 0;
    for (int i = 0; i < 2; i++)
    {
        clickCard[i] = 0;
    }
    for (int i = 0; i < 20; i++)
    {
        flag[i] = 0;
        map[i] = 0;
    }
    //屏蔽按钮的信号
    for (int i = 0; i < 20; i++)
    {
        button[i]->blockSignals(true);
    }
    b_restart->blockSignals(true);
    b_gotoui->blockSignals(true);
}