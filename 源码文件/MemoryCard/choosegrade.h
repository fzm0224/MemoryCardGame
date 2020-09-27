#ifndef CHOOSEGRADE_H
#define CHOOSEGRADE_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QLabel>

#include "primary.h"
#include "middle.h"
#include "premium.h"

class ChooseGrade : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseGrade(QWidget *parent = 0);
    ~ChooseGrade();
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    QPushButton *b_primary;
    QPushButton *b_middle;
    QPushButton *b_premium;

    QLabel *label;

    Primary primary_w;
    Middle middle_w;
    Premium premium_w;

    QPoint p;

signals:
    void mysignal();

public slots:
};

#endif // CHOOSEGRADE_H
