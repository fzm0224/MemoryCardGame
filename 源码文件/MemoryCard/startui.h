#ifndef STARTUI_H
#define STARTUI_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include "choosegrade.h"
#include "about.h"
#include "help.h"

class StartUI : public QWidget
{
    Q_OBJECT

public:
    StartUI(QWidget *parent = 0);
    ~StartUI();
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    QPushButton *b_start;
    QPushButton *b_help;
    QPushButton *b_about;
    QPushButton *b_close;

    QPoint p;

    QMediaPlayer *player;
    QMediaPlaylist *playlist;

private:
    ChooseGrade choose_w;
    Help *help;
    About *about;

signals:

public slots:
};

#endif // STARTUI_H
