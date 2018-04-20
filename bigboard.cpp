#include "bigboard.h"

BigBoard::BigBoard(QWidget *parent, unsigned int size)
{
    resize(800,800);

    setStyleSheet("\
        BigBoard {\
            background-image: url(':/images/resources/big-grid.jpg'); \
            background-repeat: no-repeat;\
            background-position: center;\
            border: 0px solid green;\
                  }");
    //setStyleSheet("border: 1px solid black;");

    setAutoFillBackground(true);

    _layout = new QGridLayout;

    /* nastavi prostor mezi okrajem gridlayoutu a rodicovskeho widgetu */
    _layout->setContentsMargins(9, 10, 10, 10);

    /* nastavi prostor mezi jednotlivymi ctvereky na 0 */
    _layout->setHorizontalSpacing(0);
    _layout->setVerticalSpacing(0);

    setLayout(_layout);

    this->_sizeOfGoban = size;
}

BigBoard::~BigBoard()
{
    //cleanBoard();
    //nextColor = "black";
    //StoneSocket::setNextColor("black");
}

/*
void BigBoard::setStoneOn(unsigned int x, unsigned int y, QString color)
{

}
*/
