#ifndef MAINBOARD_H
#define MAINBOARD_H

#include <QObject>
#include <QtWidgets>
#include "mainmenutab.h"

#include "virtualgoban.h"
#include "smallboard.h"
#include "mediumboard.h"
#include "bigboard.h"

class MainBoard : public QFrame
{
    Q_OBJECT

public:
    explicit MainBoard(QWidget *parent = 0);
    ~MainBoard();

    SmallBoard  *_smallBoard;
    MediumBoard *_mediumBoard;
    BigBoard    *_bigBoard;
    VirtualGoban *_activeBoard;

signals:
    void showBarsPlz();
    void hideBarsPlz();
    void showMenuButton();
    void hideMenuButton();
    void uncheckAllExcept(uint);
    void exitGame();

public slots:
    void printGames();
    void setSmallBoard();
    void setMediumBoard();
    void setBigBoard();
    void toMenu();
    void setTutor(bool checked);

private:
    QHBoxLayout *_mainBoardLayout;
    QVBoxLayout *_boardLayout;

    QStackedWidget *_onBoardStack;
    MainMenuTab *_mainMenuTab;

    bool _tutorChecked;

    void initActivatedBoard(unsigned int numOfWidget);
};

#endif // MAINBOARD_H
