#include "startui.h"
#include <QDebug>

StartUI::StartUI(QWidget *parent)
    : QWidget(parent)
{
    //去边框
    //setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //循环播放背景音乐
    //播放列表
    playlist = new QMediaPlaylist(this);
//    playlist->addMedia(QUrl::fromLocalFile("./music/mygame0.mp3"));
//    playlist->addMedia(QUrl::fromLocalFile("./music/mygame1.mp3"));
//    playlist->addMedia(QUrl::fromLocalFile("./music/mygame2.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("./music/mygame2.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    player = new QMediaPlayer(this);
    player->setPlaylist(playlist);
    player->setVolume(50);
    player->play();

    //初始化
    help = NULL;
    about = NULL;

    //设置字体
    QFont font;
    font.setPointSize(12);
    font.setFamily("幼圆");
    font.setBold(true);

    b_start = new QPushButton(this);
    b_start->resize(100, 40);
    b_start->move(250, 190);
    b_start->setFont(font);
    b_start->setText("开始游戏");
    b_start->setStyleSheet("QPushButton{"
                           "border-image:url(:/new/prefix1/res/a1.png)"
                           "}"

                           "QPushButton:pressed{"
                           "border-image:url(:/new/prefix1/res/a2.png)"
                           "}");

    b_help = new QPushButton(this);
    b_help->resize(100, 40);
    b_help->move(250, 240);
    b_help->setFont(font);
    b_help->setText("帮助");
    b_help->setStyleSheet("QPushButton{"
                           "border-image:url(:/new/prefix1/res/a1.png)"
                           "}"

                           "QPushButton:pressed{"
                           "border-image:url(:/new/prefix1/res/a2.png)"
                           "}");

    b_about = new QPushButton(this);
    b_about->resize(100, 40);
    b_about->move(250, 290);
    b_about->setFont(font);
    b_about->setText("关于");
    b_about->setStyleSheet("QPushButton{"
                           "border-image:url(:/new/prefix1/res/a1.png)"
                           "}"

                           "QPushButton:pressed{"
                           "border-image:url(:/new/prefix1/res/a2.png)"
                           "}");

    b_close = new QPushButton(this);
    b_close->resize(100, 40);
    b_close->move(250, 340);
    b_close->setFont(font);
    b_close->setText("退出游戏");
    b_close->setStyleSheet("QPushButton{"
                           "border-image:url(:/new/prefix1/res/a1.png)"
                           "}"

                           "QPushButton:pressed{"
                           "border-image:url(:/new/prefix1/res/a2.png)"
                           "}");

    //开始游戏
    connect(b_start, &QPushButton::pressed, this,
            [=]()
            {
                choose_w.show();
                this->hide();
            }
            );

    //帮助
    connect(b_help, &QPushButton::pressed, this,
            [=]()
            {
                help = new Help;
            }
            );

    //关于
    connect(b_about, &QPushButton::pressed, this,
            [=]()
            {
                about = new About;
            }
            );

    //退出游戏
    connect(b_close, &QPushButton::clicked, this,
            [=]()
            {
                exit(0);
            }
            );

    //处理子窗口发来的信号
    connect(&choose_w, &ChooseGrade::mysignal, this,
            [=]()
            {
                this->show();
                choose_w.hide();
            }
            );
}

StartUI::~StartUI()
{
    if (about != NULL)
    {
        delete about;
        about = NULL;
    }
    if (help != NULL)
    {
        delete help;
        help = NULL;
    }
    qDebug() << "StartUI::~StartUI()";
}

void StartUI::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void StartUI::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        move(e->globalPos() - p);
    }
}
