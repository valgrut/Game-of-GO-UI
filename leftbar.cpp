#include "leftbar.h"

LeftBar::LeftBar(QWidget *parent) : QFrame(parent)
{
    setFixedSize(350, 350);

    setStyleSheet("\
        LeftBar {\
            background-image: url(':/images/resources/bowl_mensi.png'); \
            background-repeat: no-repeat;\
            background-position: center;\
            border: 0px solid green;\
            }");

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0,0); // 10,10 ???
    shadow->setBlurRadius(70);
    shadow->setColor(QColor(0,0,0,240));
    shadow->boundingRectFor(QRect(-40,-40,40,40));
    setGraphicsEffect(shadow);

    QHBoxLayout *l = new QHBoxLayout();
    setLayout(l);

    _scoreBoard = new Score(this);
    l->setAlignment(_scoreBoard, Qt::AlignCenter);
    l->addWidget(_scoreBoard);
}
