#include "widget.h"
#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *back = new QWidget;
    back->setObjectName("MainBackground");
    back->setStyleSheet("QWidget#MainBackground {background-image: url(':/images/resources/background.jpg');}");
    QHBoxLayout *l = new QHBoxLayout;
    back->setLayout(l);

    Widget game;
    l->addWidget(&game);

    back->connect(&game, SIGNAL(exitGame()), back, SLOT(close()));

    back->show();

    return a.exec();
}
