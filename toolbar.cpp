#include "toolbar.h"

ToolBar::ToolBar(QWidget *parent) : QWidget(parent)
{
    setFixedSize(800,50);
    setStyleSheet("border-image: url(:/images/pozadi/s50.png); ");

    _layout = new QHBoxLayout(this);

    QString styles = "QPushButton:open {border-image: url(:/images/pozadi/60.png)} QPushButton:hover{border-image: url(:/images/pozadi/s30.png);}";

    _numbersButton = new QPushButton("123");
    _numbersButton->setStyleSheet("font-weight: bold;");
    _numbersButton->setToolTip("If activated, placed stones will contain sequence numbers.");
    _numbersButton->setStyleSheet(styles);
    _numbersButton->setCheckable(true);
    _numbersButton->setFixedSize(60,40);

    _triangleButton = new QPushButton;
    _triangleButton->setFixedSize(60,40);
    _triangleButton->setIcon( QIcon(":/images/resources/triangle.png") );
    _triangleButton->setToolTip("You can place triangle to some place on board.");
    _triangleButton->setStyleSheet(styles);
    _triangleButton->setCheckable(true);
    _triangleButton->setIconSize( QSize(20,20) );

    _squareButton = new QPushButton;
    _squareButton->setFixedSize(60,40);
    _squareButton->setIcon( QIcon(":/images/resources/square.png") );
    _squareButton->setToolTip("You can place square to some place on board.");
    _squareButton->setStyleSheet(styles);
    _squareButton->setCheckable(true);
    _squareButton->setIconSize( QSize(20,20) );

    _blackButton = new QPushButton;
    _blackButton->setFixedSize(60,40);
    _blackButton->setIcon( QIcon(":/images/resources/black.png") );
    _blackButton->setToolTip("While activated, only black stones will be placed.");
    _blackButton->setStyleSheet(styles);
    _blackButton->setCheckable(true);
    _blackButton->setIconSize( QSize(20,20) );

    _whiteButton = new QPushButton;
    _whiteButton->setFixedSize(60,40);
    _whiteButton->setIcon( QIcon(":/images/resources/white3.png") );
    _whiteButton->setToolTip("While activated, only white stones will be placed.");
    _whiteButton->setStyleSheet(styles);
    _whiteButton->setCheckable(true);
    _whiteButton->setIconSize( QSize(20,20) );

    _eraseButton = new QPushButton;
    _eraseButton->setFixedSize(60,40);
    _eraseButton->setIcon( QIcon(":/images/resources/eraser.png") );
    _eraseButton->setToolTip("Erase specific sequence, triangles or squares from board.");
    _eraseButton->setStyleSheet(styles);
    _eraseButton->setCheckable(true);
    _eraseButton->setIconSize( QSize(20,20) );

    _layout->addWidget(_numbersButton);
    _layout->addWidget(_triangleButton);
    _layout->addWidget(_squareButton);
    _layout->addWidget(_blackButton);
    _layout->addWidget(_whiteButton);
    _layout->addStretch();
    _layout->addWidget(_eraseButton);

    setLayout(_layout);
}

void ToolBar::uncheckAllExcept(uint opt)
{
    if(opt != 0) _numbersButton->setChecked(false);
    if(opt != 1) _triangleButton->setChecked(false);
    if(opt != 2) _squareButton->setChecked(false);
    if(opt != 3) _blackButton->setChecked(false);
    if(opt != 4) _whiteButton->setChecked(false);
    if(opt != 5) _eraseButton->setChecked(false);
}
