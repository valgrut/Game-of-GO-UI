#include "mainboard.h"

MainBoard::MainBoard(QWidget *parent) : QFrame(parent), _tutorChecked(false)
{
    setFixedSize(800,800);

    setStyleSheet("\
        MainBoard {\
            background-image: url(':/images/resources/plane-board-text3.jpg'); \
            background-repeat: no-repeat;\
            background-position: center;\
            border: 0px solid green;\
                  }");

    _mainMenuTab = new MainMenuTab;
    _smallBoard = new SmallBoard(this, 9);
    _mediumBoard = new MediumBoard(this, 13);
    _bigBoard = new BigBoard(this, 19);

    _onBoardStack = new QStackedWidget;
    _onBoardStack->addWidget(_mainMenuTab); //0
    _onBoardStack->addWidget(_smallBoard);  //1
    _onBoardStack->addWidget(_mediumBoard); //2
    _onBoardStack->addWidget(_bigBoard);    //3

    _boardLayout = new QVBoxLayout;
    _mainBoardLayout = new QHBoxLayout;

    _boardLayout->addWidget(_onBoardStack);
    _mainBoardLayout->addLayout(_boardLayout);

    _boardLayout->setContentsMargins(0, 0, 0, 0);

    setLayout(_mainBoardLayout);

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0,0); // 10,10 ???
    shadow->setBlurRadius(70);
    shadow->setColor(QColor(0,0,0,240));
    shadow->boundingRectFor(QRect(-40,-40,40,40));
    setGraphicsEffect(shadow);

    connect(_mainMenuTab, SIGNAL(createSmallBoardSig()), this, SLOT(setSmallBoard()));
    connect(_mainMenuTab, SIGNAL(createMediumBoardSig()), this, SLOT(setMediumBoard()));
    connect(_mainMenuTab, SIGNAL(createBigBoardSig()), this, SLOT(setBigBoard()));
    connect(_mainMenuTab, SIGNAL(loadGameSig()), this, SLOT(printGames()));
    connect(_mainMenuTab, SIGNAL(continueGameSig()), this, SLOT(printGames()));
    connect(_mainMenuTab, SIGNAL(tutorChecked(bool)), this, SLOT(setTutor(bool)));
    connect(_mainMenuTab, SIGNAL(exitGame()), SIGNAL(exitGame()));
}

MainBoard::~MainBoard()
{
    //destruktor
}

void MainBoard::setTutor(bool checked)
{
    this->_tutorChecked = checked;
}

void MainBoard::printGames()
{
    qDebug() << "printGames";
}

void MainBoard::initActivatedBoard(unsigned int numOfWidget)
{
    _onBoardStack->setCurrentIndex(numOfWidget);
    _activeBoard = static_cast<VirtualGoban*>(_onBoardStack->widget(numOfWidget));
    if(this->_tutorChecked) emit showBarsPlz();
    emit showMenuButton();

    connect(_activeBoard, SIGNAL(uncheckAllExcept(uint)), this, SIGNAL(uncheckAllExcept(uint)));
}

void MainBoard::setSmallBoard()
{
    qDebug() << "set Small";
    //_smallBoard->cleanBoard();
    _smallBoard->generateBoard(9);
    initActivatedBoard(1);
}

void MainBoard::setMediumBoard()
{
    qDebug() << "set Medium";
    //_mediumBoard->cleanBoard();
    _mediumBoard->generateBoard(13);
    initActivatedBoard(2);
}

void MainBoard::setBigBoard()
{
    qDebug() << "set Big";
    //_bigBoard->cleanBoard();
    _bigBoard->generateBoard(19);
    initActivatedBoard(3);
}

void MainBoard::toMenu()
{
    qDebug() << "zpet do menu";
    _onBoardStack->setCurrentIndex(0);

    //deinicializovat hru
    //_activeBoard->cleanBoard();

    emit hideBarsPlz();
    emit hideMenuButton();
}

