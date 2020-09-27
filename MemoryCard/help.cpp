#include "help.h"

Help::Help(QWidget *parent) : QDialog(parent)
{
    //固定窗口大小
    this->setFixedSize(400, 300);
    this->setAutoFillBackground(true);

    QPalette palette;
    QPixmap pixmap(":/new/prefix1/res/bg666.jpg");
    palette.setBrush(QPalette::Background, QBrush(pixmap.scaled(this->size(),
                                              Qt::IgnoreAspectRatio,
                                              Qt::SmoothTransformation)));
    this->setPalette(palette);


    label_title = new QLabel(this);
    label_title->resize(160, 40);
    label_title->move(120, 20);
    label_title->setText(QString("<center><h1>游戏规则</h1></center>"));
    label_title->setStyleSheet("QLabel{"
                               "border-image:url(:/new/prefix1/res/title.jpg)"
                               "}");

    QFont fontlabel;
    fontlabel.setPointSize(13);
    fontlabel.setFamily("幼圆");
    fontlabel.setBold(true);

    label_cont = new QLabel(this);
    label_cont->resize(270, 190);
    label_cont->move(65, 85);
    //自动换行
    label_cont->setWordWrap(true);
    //顶端开始
    label_cont->setAlignment(Qt::AlignTop);
    label_cont->setFont(fontlabel);
    label_cont->setText("    游戏开始选择难度后，进入游戏界面，开始倒计时5秒钟，5秒钟后卡牌翻转为正面，每两张为一对，随机分散在各处，"
                        "在给定时间内记忆每对卡牌的位置，时间到后卡牌翻转为反面，这时你需要根据自己的记忆开始翻转卡牌，"
                        "前后两次翻转的卡牌必须为一对，错误则游戏失败，全部正确反转则游戏胜利。");

    label_cont->setStyleSheet("QLabel{"
                              "background-color:skyblue"
                              "}");

    this->exec();
}

Help::~Help()
{

}

