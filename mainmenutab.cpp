#include "mainmenutab.h"

MainMenuTab::MainMenuTab(QWidget *parent) : QFrame(parent)
{
    setStyleSheet("MainMenuTab {border: 3px solid black; margin: 28px; margin-top: 95px;}");

    _mainMenuLayout = new QHBoxLayout;
    _leftLayout = new QVBoxLayout;
    _rightLayout = new QVBoxLayout;

    _createSmallBoardButton = new MenuButton();
    _createSmallBoardButton->setToolTip("Creates new 9x9 game.\nIf Tutorial button is checked, game will be started with advanced options.");
    _createSmallBoardButton->setText("9x9");

    _createMediumBoardButton = new MenuButton();
    _createMediumBoardButton->setToolTip("Creates new 13x13 game.\nIf Tutorial button is checked, game will be started with advanced options.");
    _createMediumBoardButton->setText("13x13");

    _createBigBoardButton = new MenuButton();
    _createBigBoardButton->setToolTip("Creates new 9x19 game.\nIf Tutorial button is checked, game will be started with advanced options.");
    _createBigBoardButton->setText("19x19");

    _loadGameButton = new MenuButton();
    _loadGameButton->setText("Load Game");

    _continueGameButton = new MenuButton();
    _continueGameButton->setText("Exit Game");
    //_continueGameButton->setFixedHeight(60);

    _advancedButton = new MenuButton();
    _advancedButton->setText("Activate\nTutorial Mod");
    _advancedButton->setStyleSheet(  "QPushButton { border-image: url(:/images/pozadi/s50.png);\
                                     border: 2px solid brown;\
                                     border-radius: 10px;\
                                     font-size: 30px;\
                                     font-family: palatino;\
                                     font-weight: bold;}\
                                     QPushButton:open {border-image: url(:/images/pozadi/s80.png);}");
    _advancedButton->setToolTip("Timto tlacitkem se spusti vyukovy mod.");
    _advancedButton->setToolTipDuration(3000);
    _advancedButton->setCheckable(true);

    _leftLayout->addStretch();
    _leftLayout->addWidget(_advancedButton);
    _leftLayout->addStretch();
    _leftLayout->addWidget(_loadGameButton);
    _leftLayout->addStretch();
    //_leftLayout->addSpacing(120);
    _leftLayout->addWidget(_continueGameButton);
    _leftLayout->addStretch();

    _rightLayout->addStretch();
    _rightLayout->addWidget(_createSmallBoardButton);
    _rightLayout->addStretch();
    _rightLayout->addWidget(_createMediumBoardButton);
    _rightLayout->addStretch();
    _rightLayout->addWidget(_createBigBoardButton);
    _rightLayout->addStretch();

    _mainMenuLayout->addLayout(_leftLayout);
    _mainMenuLayout->addLayout(_rightLayout);

    setLayout(_mainMenuLayout);

    connect(_createSmallBoardButton, SIGNAL(clicked(bool)), SIGNAL(createSmallBoardSig()));
    connect(_createMediumBoardButton, SIGNAL(clicked(bool)), SIGNAL(createMediumBoardSig()));
    connect(_createBigBoardButton, SIGNAL(clicked(bool)), SIGNAL(createBigBoardSig()));
    connect(_loadGameButton, SIGNAL(clicked(bool)), SIGNAL(loadGameSig()));
    connect(_continueGameButton, SIGNAL(clicked(bool)), SIGNAL(exitGame()));
    connect(_advancedButton, SIGNAL(toggled(bool)), SIGNAL(tutorChecked(bool)));
}

MainMenuTab::~MainMenuTab()
{
    // destructor
}
