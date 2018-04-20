#ifndef MAINMENUTAB_H
#define MAINMENUTAB_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QCheckBox>
#include "menubutton.h"

class MainMenuTab : public QFrame
{
    Q_OBJECT

public:
    MainMenuTab(QWidget *parent = 0);
    ~MainMenuTab();

signals:
    void createSmallBoardSig();
    void createMediumBoardSig();
    void createBigBoardSig();

    void loadGameSig();
    void continueGameSig();

    void tutorChecked(bool);

    void exitGame();

private:
    QHBoxLayout *_mainMenuLayout;
    QVBoxLayout *_leftLayout;
    QVBoxLayout *_rightLayout;

    MenuButton *_createSmallBoardButton;
    MenuButton *_createMediumBoardButton;
    MenuButton *_createBigBoardButton;

    MenuButton *_advancedButton;

    MenuButton *_loadGameButton;
    MenuButton *_continueGameButton;
};

#endif // MAINMENUTAB_H
