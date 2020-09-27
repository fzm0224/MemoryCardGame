#include "choosegrade.h"
#include <QDebug>

ChooseGrade::ChooseGrade(QWidget *parent) : QWidget(parent)
{
    //设置窗口固定大小，图片自适应
    setFixedSize(500, 300);
    setAutoFillBackground(true);

    QPalette palette;
    QPixmap pixmap(":/new/prefix1/res/bg111.jpg");
    palette.setBrush(QPalette::Background, QBrush(pixmap.scaled(this->size(),
                                              Qt::IgnoreAspectRatio,
                                              Qt::SmoothTransformation)));
    setPalette(palette);

    //去边框
    //setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    label = new QLabel(this);
    label->move(125, 30);
    label->resize(250, 60);
    label->setText("<center><h1><font color=white>请选择游戏难度？</font></h1></center>");
    label->setStyleSheet("QLabel{"
                         "border-image:url(:/new/prefix1/res/title111.jpg)"
                         "}");


    //设置字体
    QFont font;
    font.setPointSize(12);
    font.setFamily("幼圆");
    font.setBold(true);

    b_primary = new QPushButton(this);
    b_primary->move(50, 220);
    b_primary->resize(100, 40);
    b_primary->setFont(font);
    b_primary->setText(QString("初级难度"));
    b_primary->setStyleSheet("QPushButton{"
                             "border-image:url(:/new/prefix1/res/a1.png)"
                             "}"

                             "QPushButton:clicked{"
                             "border-image:url(:/new/prefix1/res/a2.png)"
                             "}");


    b_middle = new QPushButton(this);
    b_middle->move(200, 220);
    b_middle->resize(100, 40);
    b_middle->setFont(font);
    b_middle->setText(QString("中级难度"));
    b_middle->setStyleSheet("QPushButton{"
                             "border-image:url(:/new/prefix1/res/a1.png)"
                             "}"

                             "QPushButton:clicked{"
                             "border-image:url(:/new/prefix1/res/a2.png)"
                             "}");


    b_premium = new QPushButton(this);
    b_premium->move(350, 220);
    b_premium->resize(100, 40);
    b_premium->setFont(font);
    b_premium->setText(QString("高级难度"));
    b_premium->setStyleSheet("QPushButton{"
                             "border-image:url(:/new/prefix1/res/a1.png)"
                             "}"

                             "QPushButton:clicked{"
                             "border-image:url(:/new/prefix1/res/a2.png)"
                             "}");

    //初级难度按钮
    connect(b_primary, &QPushButton::pressed, this,
            [=]()
            {
                primary_w.setFixedSize(600, 680);
                primary_w.startTimer_pri();

                primary_w.show();
                this->hide();
            }
            );

    //中级难度按钮
    connect(b_middle, &QPushButton::pressed, this,
            [=]()
            {
                middle_w.setFixedSize(600, 680);
                middle_w.startTimer_mid();

                middle_w.show();
                this->hide();
            }
            );

    //高级难度按钮
    connect(b_premium, &QPushButton::pressed, this,
            [=]()
            {
                premium_w.setFixedSize(600, 680);
                premium_w.startTimer_pre();

                premium_w.show();
                this->hide();
            }
            );

    connect(&primary_w, &Primary::mysignal_pri, this,
            [=]()
            {
                emit mysignal();
                primary_w.restart_func();
                primary_w.hide();
            }
            );

    connect(&middle_w, &Middle::mysignal_mid, this,
            [=]()
            {
                emit mysignal();
                middle_w.restart_func();
                middle_w.hide();
            }
            );

    connect(&premium_w, &Premium::mysignal_pre, this,
            [=]()
            {
                emit mysignal();
                premium_w.restart_func();
                premium_w.hide();
            }
            );
}

ChooseGrade::~ChooseGrade()
{

}

void ChooseGrade::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void ChooseGrade::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        move(e->globalPos() - p);
    }
}

