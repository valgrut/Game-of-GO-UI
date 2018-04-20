#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), _connectedBars(false)
{
    resize(1400,900);
    setMinimumWidth(1540);
    setMinimumHeight(950);

    setStyleSheet("Widget {background-color: brown;}");

    setAutoFillBackground(true);

    _mainLayout = new QHBoxLayout(this);
    _leftLayout = new QVBoxLayout;
    _middleLayout = new QVBoxLayout;
    _rightLayout = new QVBoxLayout;

    /* inicializace widgetů (prvky hry) */
    _mainBoard = new MainBoard(this);
    _bottomBar = new BottomBar(this);
    _bottomBar->hide();
    _toolBar = new ToolBar(this);
    _toolBar->hide();
    _menuButton = new QPushButton("Pass");
    _menuButton->setStyleSheet(  "QPushButton { border-image: url(:/images/pozadi/s30.png);\
                                        border-radius: 10px;\
                                        font-weight: bold;\
                                        font-family: palatino;\
                                        font-size: 40px;}\
                                        QPushButton:pressed { border-image: url(:/images/pozadi/s80.png); }\
                                        QPushButton:hover {border-image: url(:/images/pozadi/s50.png);}\
                                        ");
    _menuButton->setToolTip("Pass the game and return to main menu.");
    _menuButton->setFixedSize(280, 50);
    _menuButton->hide();

    _leftBar = new LeftBar;
    _rightBar = new LeftBar;

    /* naplnime levy layout <><> */
    _leftLayout->addWidget(_leftBar);
    _leftLayout->addStretch();
    _leftLayout->addWidget(_menuButton);

    /* naplnime prostredni layout <><> */
    _middleLayout->addWidget(_toolBar);
    _middleLayout->addWidget(_mainBoard);
    _middleLayout->addWidget(_bottomBar);

    /* naplnime pravy layout <><> */
    _rightLayout->addStretch();
    _rightLayout->addWidget(_rightBar);

    /* layouty se vlozi do hlavniho layoutu */
    _mainLayout->addLayout(_leftLayout);
    _mainLayout->addLayout(_middleLayout);
    _mainLayout->addLayout(_rightLayout);

    setLayout(_mainLayout);

    connect(_mainBoard, SIGNAL(showBarsPlz()), this, SLOT(showBars()));
    connect(_mainBoard, SIGNAL(hideBarsPlz()), this, SLOT(hideBars()));

    connect(this->_menuButton, SIGNAL(clicked(bool)), this->_mainBoard, SLOT(toMenu()));

    connect(_mainBoard, SIGNAL(showMenuButton()), this, SLOT(showMenuButton()));
    connect(_mainBoard, SIGNAL(hideMenuButton()), this, SLOT(hideMenuButton()));

    connect(_mainBoard, SIGNAL(uncheckAllExcept(uint)), this->_toolBar, SLOT(uncheckAllExcept(uint)));
    connect(_mainBoard, SIGNAL(exitGame()), this, SIGNAL(exitGame()));
}

Widget::~Widget()
{

}

void Widget::connectWidgets()
{
    if(_connectedBars == false)
    {
        /* propojeni BottomBaru se sloty */
        connect(_bottomBar->_beginButton, SIGNAL(clicked(bool)), _mainBoard->_activeBoard, SLOT(toStart()));
        connect(_bottomBar->_nextMoveButton, SIGNAL(clicked(bool)), _mainBoard->_activeBoard, SLOT(nextMove()));
        connect(_bottomBar->_prevMoveButton, SIGNAL(clicked(bool)), _mainBoard->_activeBoard, SLOT(prevMove()));
        connect(_bottomBar->_endButton, SIGNAL(clicked(bool)), _mainBoard->_activeBoard, SLOT(toEnd()));

        /* propojeni ToolBaru se sloty */
        connect(_toolBar->_numbersButton, SIGNAL(toggled(bool)), _mainBoard->_activeBoard, SLOT(setSequence(bool)));
        connect(_toolBar->_triangleButton, SIGNAL(toggled(bool)), _mainBoard->_activeBoard, SLOT(setTriangle(bool)));
        connect(_toolBar->_squareButton, SIGNAL(toggled(bool)), _mainBoard->_activeBoard, SLOT(setSquare(bool)));
        connect(_toolBar->_blackButton, SIGNAL(toggled(bool)), _mainBoard->_activeBoard, SLOT(setBlackOnly(bool)));
        connect(_toolBar->_whiteButton, SIGNAL(toggled(bool)), _mainBoard->_activeBoard, SLOT(setWhiteOnly(bool)));
        connect(_toolBar->_eraseButton, SIGNAL(toggled(bool)), _mainBoard->_activeBoard, SLOT(setErase(bool)));

        _connectedBars = true;
    }
}

void Widget::showMenuButton()
{
    _menuButton->show();
    _leftBar->_scoreBoard->show();
    _rightBar->_scoreBoard->show();
}

void Widget::hideMenuButton()
{
    _menuButton->hide();
    _leftBar->_scoreBoard->hide();
    _rightBar->_scoreBoard->hide();
}

void Widget::showBars()
{
    connectWidgets();
    showBottomBar();
    showToolBar();
}

void Widget::showBottomBar()
{
    _bottomBar->show();
}

void Widget::showToolBar()
{
    _toolBar->show();
}

void Widget::hideBars()
{
    hideBottomBar();
    hideToolBar();
}

void Widget::hideBottomBar()
{
    _bottomBar->hide();
}

void Widget::hideToolBar()
{
    _toolBar->hide();
}
