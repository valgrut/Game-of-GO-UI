#include "mediumboard.h"

MediumBoard::MediumBoard(QWidget *parent, unsigned int size)
{
    resize(800,800);

    setStyleSheet("\
        MediumBoard {\
            background-image: url(':/images/resources/mid-grid.jpg'); \
            background-repeat: no-repeat;\
            background-position: center;\
            border: 0px solid green;\
            }");
    //setStyleSheet("border: 1px solid black;");

    setAutoFillBackground(true);

    _layout = new QGridLayout;

    /* nastavi prostor mezi okrajem gridlayoutu a rodicovskeho widgetu */
    _layout->setContentsMargins(130, 130, 130, 130);

    /* nastavi prostor mezi jednotlivymi ctvereky na 0 */
    _layout->setHorizontalSpacing(0);
    _layout->setVerticalSpacing(0);

    setLayout(_layout);

    this->_sizeOfGoban = size;
}

MediumBoard::~MediumBoard()
{
    //cleanBoard();
    //nextColor = "black";
    //StoneSocket::setNextColor("black");
}

