#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>

class GameOver : public QDialog
{
    Q_OBJECT
public:
    explicit GameOver(bool x, int grade, QWidget *parent = 0);
    ~GameOver();

private:
    void gameover_w(bool x, int grade);

private:
    QLabel *label_title;
    QLabel *label_movie;

    QPushButton *b_close;

signals:

public slots:
};

#endif // GAMEOVER_H
