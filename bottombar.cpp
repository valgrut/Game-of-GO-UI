#include "bottombar.h"

BottomBar::BottomBar(QWidget *parent) : QWidget(parent)
{
    setFixedSize(800, 50);
    setStyleSheet("border-image: url(:/images/pozadi/s50.png);\
                  font-weight: bold;\
                  font-family: palatino;\
                  font-size: 20px;\
    ");

    _layout = new QHBoxLayout(this);

    QString styles = "QPushButton:hover {border-image: url(:/images/pozadi/s70.png);}";

    _nextMoveButton = new QPushButton(">");
    _nextMoveButton->setStyleSheet(styles);
    _nextMoveButton->setToolTip("go one move forward");
    _nextMoveButton->setFixedSize(150, 50);

    _prevMoveButton = new QPushButton("<");
    _prevMoveButton->setStyleSheet(styles);
    _prevMoveButton->setToolTip("go one move backward");
    _prevMoveButton->setFixedSize(150, 50);

    _endButton = new QPushButton(">>|");
    _endButton->setStyleSheet(styles);
    _endButton->setToolTip("go to last move");
    _endButton->setFixedSize(150, 50);

    _beginButton = new QPushButton("|<<");
    _beginButton->setStyleSheet(styles);
    _beginButton->setToolTip("go to start of game");
    _beginButton->setFixedSize(150, 50);

    _layout->addWidget(_beginButton);
    _layout->addWidget(_prevMoveButton);

    _layout->addStretch();

    _layout->addWidget(_nextMoveButton);
    _layout->addWidget(_endButton);

    setLayout(_layout);
}
