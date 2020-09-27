#include "startui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartUI w;

    w.setFixedSize(600, 400);
//    w.setWindowIcon(QIcon("crown.ico"));
//    w.setWindowTitle("记忆力大师");
    w.setAutoFillBackground(true);

    QPalette palette;
    QPixmap pixmap(":/new/prefix1/res/ui.jpg");
    palette.setBrush(QPalette::Background, QBrush(pixmap.scaled(w.size(),
                                              Qt::IgnoreAspectRatio,
                                              Qt::SmoothTransformation)));
    w.setPalette(palette);

    w.show();

    return a.exec();
}
