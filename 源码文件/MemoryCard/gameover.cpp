#include "gameover.h"
#include <QMovie>

GameOver::GameOver(bool x, int grade, QWidget *parent) : QDialog(parent)
{
    this->setFixedSize(500, 370);
    this->setAutoFillBackground(true);

    QPalette palette;
    QPixmap pixmap(":/new/prefix1/res/bg666.jpg");
    palette.setBrush(QPalette::Background, QBrush(pixmap.scaled(this->size(),
                                              Qt::IgnoreAspectRatio,
                                              Qt::SmoothTransformation)));
    this->setPalette(palette);

    //设置字体
    QFont font;
    font.setPointSize(12);
    font.setFamily("幼圆");
    font.setBold(true);

    label_title = new QLabel(this);
    label_title->resize(260 ,50);
    label_title->move(120 ,20);
    label_title->setStyleSheet("QLabel{"
                               "border-image:url(:/new/prefix1/res/title.jpg)"
                               "}");
//    label_title->setStyleSheet("QLabel{"
//                               "background-color:red"
//                               "}");

    label_movie = new QLabel(this);
    label_movie->resize(460 ,200);
    label_movie->move(20, 90);
//    label_movie->setStyleSheet("QLabel{"
//                               "background-color:green"
//                               "}");

    b_close = new QPushButton(this);
    b_close->resize(100, 40);
    b_close->setFont(font);
    b_close->setText("关闭");
    b_close->move(200 ,310);
    b_close->setStyleSheet("QPushButton{"
                             "border-image:url(:/new/prefix1/res/a2.png)"
                             "}"

                             "QPushButton:pressed{"
                             "border-image:url(:/new/prefix1/res/a1.png)"
                             "}");

    //关闭按钮
    connect(b_close, &QPushButton::pressed, this,
            [=]()
            {
                this->close();
            }
            );

    gameover_w(x, grade);

    exec();;
}

GameOver::~GameOver()
{

}

void GameOver::gameover_w(bool x, int grade)
{
    QMovie * movie;
    QString str;

    if (x == true)
    {
        if (grade == 1)
        {
            str = QString("<center><h1>初级难度挑战成功!</h1></center>");
        }
        else if (grade == 2)
        {
            str = QString("<center><h1>中级难度挑战成功!</h1></center>");
        }
        else
        {
            str = QString("<center><h1>高级难度挑战成功!</h1></center>");
        }

        //创建动画
        movie = new QMovie(":/new/prefix1/res/nice.gif");
    }
    else
    {
        if (grade == 1)
        {
            str = QString("<center><h1>初级难度挑战失败!</h1></center>");
        }
        else if (grade == 2)
        {
            str = QString("<center><h1>中级难度挑战失败!</h1></center>");
        }
        else
        {
            str = QString("<center><h1>高级难度挑战失败!</h1></center>");
        }

        //创建动画
        movie = new QMovie(":/new/prefix1/res/fail.gif");
    }

    label_title->setText(str);

    //设置动画
    label_movie->setMovie(movie);
    //启动动画
    movie->start();
    label_movie->setScaledContents(true);
}
