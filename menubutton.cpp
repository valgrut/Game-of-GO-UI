#include "menubutton.h"

MenuButton::MenuButton(QWidget *parent) : QPushButton(parent)
{
    setFixedSize(300, 180); //250, 120
    setStyleSheet(  "QPushButton { border-image: url(:/images/pozadi/30.png);\
                    border-radius: 10px;\
                    font-weight: bold;\
                    font-family: palatino;\
                    font-size: 40px;}\
                    QPushButton:pressed { border-image: url(:/images/pozadi/s80.png); }\
                    QPushButton:hover {border-image: url(:/images/pozadi/40.png);}\
                    ");
}
