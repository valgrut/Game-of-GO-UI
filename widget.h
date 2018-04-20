#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "mainboard.h"
#include "bottombar.h"
#include "toolbar.h"
#include "leftbar.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void connectWidgets();
public slots:
    void showBars();
    void showBottomBar();
    void showToolBar();

    void hideBars();
    void hideBottomBar();
    void hideToolBar();

    void showMenuButton();
    void hideMenuButton();

signals:
    void exitGame();

private:
    QHBoxLayout *_mainLayout;
    QVBoxLayout *_leftLayout;
    QVBoxLayout *_middleLayout;
    QVBoxLayout *_rightLayout;

    MainBoard *_mainBoard;
    BottomBar *_bottomBar;
    ToolBar *_toolBar;
    LeftBar *_leftBar;
    LeftBar *_rightBar;

    QPushButton *_menuButton;

    bool _connectedBars;
};

#endif // WIDGET_H
