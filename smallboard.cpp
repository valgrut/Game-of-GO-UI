#include "smallboard.h"

SmallBoard::SmallBoard(QWidget *parent, unsigned int size)
{
    resize(800,800);

    setStyleSheet("\
            SmallBoard {\
            background-image: url(:/images/resources/small-grid.jpg); \
            background-repeat: no-repeat;\
            background-position: center;\
            border: 0px solid green;\
        }");

    //setStyleSheet("border: 1px solid black;");

    _layout = new QGridLayout;

    /* nastavi prostor mezi okrajem gridlayoutu a rodicovskeho widgetu */
    _layout->setContentsMargins(210, 208, 209, 205);

    /* nastavi prostor mezi jednotlivymi ctvereky na 0 */
    _layout->setHorizontalSpacing(0);
    _layout->setVerticalSpacing(0);

    setLayout(_layout);

    this->_sizeOfGoban = size;
}

SmallBoard::~SmallBoard()
{
    //cleanBoard();
    //nextColor = "black";
    //StoneSocket::setNextColor("black");
}

